#include "lambertian.h"

std::optional<scatter_record> lambertian::scatter(const ray &r, const hit_record &rec) const {
    vec3 direction_scatter = rec.normal + vec3::random_unit();;

    scatter_record ret(albedo);
    ret.add(ray(rec.p, direction_scatter), 1 - absorption);
    return ret;
}