#include "metal.h"

std::optional<scatter_record> metal::scatter(const ray &r, const hit_record &rec) const {
    vec3 direction_reflect = vec3::unit_vector(r.get_direction());
    direction_reflect = direction_reflect -
                        2 * dot(direction_reflect, unit_vector(rec.normal)) * unit_vector(rec.normal);
    direction_reflect += vec3::random_unit() * reflection_scatter;
    scatter_record ret(albedo);
    ret.add(ray(rec.p, direction_reflect), 1.0);
    return ret;
}