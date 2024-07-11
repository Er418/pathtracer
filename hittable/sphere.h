#ifndef BASIC_RAYTRACING_SPHERE_H
#define BASIC_RAYTRACING_SPHERE_H

#include "hittable.h"

class sphere : public hittable {
public:
    sphere() : center(0, 0, 0), radius(0) {};

    sphere(point3 center, double radius) : center(center), radius(radius) {}

    std::optional<hit_record> hit(const ray &r, interval ray_t) const override;

private:
    point3 center;
    double radius;
};

#endif //BASIC_RAYTRACING_SPHERE_H
