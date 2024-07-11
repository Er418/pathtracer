#ifndef BASIC_RAYTRACING_HITTABLE_H
#define BASIC_RAYTRACING_HITTABLE_H

#include <optional>
#include "../utils/utils.h"
#include "../utils/interval.h"
#include "../basic_types/types.h"

class hit_record {
public:
    point3 p;
    vec3 normal;
    double t = 0.0;
    bool front_face = false;

    void set_face_normal(const ray &r, const vec3 &outward_normal) {
        front_face = dot(r.get_direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual std::optional<hit_record> hit(const ray &r, interval ray_t) const = 0;
};

#endif //BASIC_RAYTRACING_HITTABLE_H
