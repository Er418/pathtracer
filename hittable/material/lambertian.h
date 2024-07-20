#ifndef BASIC_RAYTRACING_LAMBERTIAN_H
#define BASIC_RAYTRACING_LAMBERTIAN_H

#include "material.h"

class lambertian : public material {
public:
    lambertian(const color &color_ = color(), const double &albedo_ = 1.0) :
            color_value(color_),
            albedo(albedo_) {}

    std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const override;
private:
    color color_value;
    double albedo;
};


#endif //BASIC_RAYTRACING_LAMBERTIAN_H
