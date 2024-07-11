#include "hittable_list.h"

hittable_list::hittable_list(const hittable_ptr &object) {
    add(object);
}

void hittable_list::add(const hittable_ptr &object) {
    objects.push_back(object);
}

std::optional<hit_record> hittable_list::hit(const ray &r, interval ray_t) const {
    std::optional<hit_record> closest_hit = std::nullopt;
    auto closest_so_far = ray_t.max;

    for (const auto &object: objects) {
        auto hit = object->hit(r, interval(ray_t.min, closest_so_far));
        if (hit.has_value()) {
            closest_hit = hit;
            closest_so_far = hit->t;
        }
    }

    return closest_hit;
}
