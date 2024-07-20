#ifndef BASIC_RAYTRACING_MATERIAL_H
#define BASIC_RAYTRACING_MATERIAL_H

#include <optional>

#include "../../utils/utils.h"
#include "../../types/types.h"
#include "../hittable.h"

class scattered_ray {
public:
    scattered_ray(const ray &ray_, const double &weight_) :
            ray_value(ray_),
            weight(weight_) {}

    scattered_ray(const color &color_, const double &weight_) :
            color_value(color_),
            weight(weight_) {}

    std::optional<ray> ray_value;
    std::optional<color> color_value;
    double weight = 0.0;
};

class scatter_record {
public:


    void add(const ray &ray_, const double &weight_) {
        rays.emplace_back(ray_, weight_);
    }


    void add(const color &color_, const double &weight_) {
        rays.emplace_back(color_, weight_);
    }

    std::vector<scattered_ray> get_rays() const {
        return rays;
    }

private:
    std::vector<scattered_ray> rays;
};


class material {
public:
    virtual std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const {
        return std::nullopt;
    }
private:

};


#endif //BASIC_RAYTRACING_MATERIAL_H
