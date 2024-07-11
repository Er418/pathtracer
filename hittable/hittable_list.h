#ifndef BASIC_RAYTRACING_HITTABLE_LIST_H
#define BASIC_RAYTRACING_HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <utility>
#include <vector>

using hittable_ptr = shared_ptr<hittable>;

class hittable_list : public hittable {
public:
    hittable_list() = default;

    hittable_list(const hittable_ptr& object);

    void clear() { objects.clear(); }

    void add(const hittable_ptr& object);

    std::optional<hit_record> hit(const ray &r, interval ray_t) const override;

private:
    std::vector<hittable_ptr> objects;
};

#endif //BASIC_RAYTRACING_HITTABLE_LIST_H
