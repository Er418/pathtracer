#ifndef BASIC_RAYTRACING_SPHERE_H
#define BASIC_RAYTRACING_SPHERE_H

#include <utility>

#include "../hittable.h"
#include "../material/materials.h"

class sphere : public hittable {
public:
    sphere() :
            center(0, 0, 0),
            radius(0),
            mat(make_shared<material>(default_material)) {};

    sphere(point3 center_, double radius_, shared_ptr<material> mat_) :
            center(center_),
            radius(radius_),
            mat(std::move(mat_)) {}

    std::optional<hit_record> hit(const ray &r, interval ray_t) const override;

private:
    point3 center;
    double radius;
    shared_ptr<material> mat;
};

#endif //BASIC_RAYTRACING_SPHERE_H
