#ifndef BASIC_RAYTRACING_METAL_H
#define BASIC_RAYTRACING_METAL_H

#include "material.h"


class metal : public material {
public:
    metal(const color &color_ = color(), const double &absorption_ = 0.0, const double &reflection_scatter_ = 0.0) :
            albedo(color_),
            absorption(absorption_),
            reflection_scatter(reflection_scatter_) {}

    std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const override;

private:
    color albedo;
    double absorption;
    double reflection_scatter;
};


#endif //BASIC_RAYTRACING_METAL_H
