#ifndef BASIC_RAYTRACING_EMMISIVE_H
#define BASIC_RAYTRACING_EMMISIVE_H

#include "material.h"

class emmisive : public material {
public:
    emmisive(const color &color_ = color(), const double &brightness_ = 1.0) :
            color_value(color_),
            brightness(brightness_) {}

    std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const override;

private:
    color color_value;
    double brightness;
};


#endif //BASIC_RAYTRACING_EMMISIVE_H
