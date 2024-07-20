#include "lambertian.h"

std::optional<scatter_record> lambertian::scatter(const ray &r, const hit_record &rec) const {
    vec3 direction_scatter = rec.normal + vec3::random_unit();;

    scatter_record ret;
    ret.add(ray(rec.p, direction_scatter), albedo);
    ret.add(color_value, 1 - albedo);
    return ret;
}