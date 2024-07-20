#ifndef BASIC_RAYTRACING_LAMBERTIAN_H
#define BASIC_RAYTRACING_LAMBERTIAN_H

#include "material.h"

class lambertian : public material {
public:
    lambertian(const color &color_ = color()) :
            albedo(color_) {}

    std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const override;
private:
    color albedo;
};


#endif //BASIC_RAYTRACING_LAMBERTIAN_H
