#ifndef BASIC_RAYTRACING_METAL_H
#define BASIC_RAYTRACING_METAL_H

#include "material.h"


class metal : public material {
public:
    metal(const color &color_ = color(), const double &albedo_ = 1.0, const double &reflect_ = 0.0) :
            color_value(color_),
            albedo(albedo_),
            reflection_scatter(reflect_) {}

    std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const override;

private:
    color color_value;
    double reflection_scatter;
    double albedo;
};


#endif //BASIC_RAYTRACING_METAL_H
