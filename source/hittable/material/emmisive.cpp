#include "emmisive.h"

std::optional<scatter_record> emmisive::scatter(const ray &r, const hit_record &rec) const {
    vec3 direction_scatter = rec.normal + vec3::random_unit();;

    scatter_record ret(color_value);
    ret.add(color_value, brightness);
    return ret;
}