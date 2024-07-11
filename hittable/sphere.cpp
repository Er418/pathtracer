#include "sphere.h"

std::optional <hit_record> sphere::hit(const ray &r, interval ray_t) const {
    vec3 oc = center - r.get_origin();
    auto a = r.get_direction().length_squared();
    auto h = dot(r.get_direction(), oc);
    auto c = oc.length_squared() - radius * radius;

    auto discriminant = h * h - a * c;
    if (discriminant < 0) {
        return std::nullopt;
    }

    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (h - sqrtd) / a;
    if (root <= ray_t.min || ray_t.max <= root) {
        root = (h + sqrtd) / a;
        if (root <= ray_t.min || ray_t.max <= root)
            return std::nullopt;
    }
    hit_record rec;
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return rec;
}