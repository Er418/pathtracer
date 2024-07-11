#ifndef BASIC_RAYTRACING_RAY_H
#define BASIC_RAYTRACING_RAY_H

#include "vec3.h"

class ray {
public:
    ray() = default;

    ray(const point3 &origin, const vec3 &direction) : origin(origin), direction(direction) {}

    point3 get_origin() const { return origin; }

    vec3 get_direction() const { return direction; }

    point3 at(double t) const {
        return origin + t * direction;
    }

private:
    point3 origin;
    vec3 direction;
};

#endif //BASIC_RAYTRACING_RAY_H
