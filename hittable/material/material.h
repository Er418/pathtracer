#ifndef BASIC_RAYTRACING_MATERIAL_H
#define BASIC_RAYTRACING_MATERIAL_H

#include <optional>

#include "../../utils/utils.h"
#include "../../types/types.h"
#include "../hittable.h"

class scatter_record {

};


class material {
public:
    std::optional<scatter_record> scatter(const ray &r, const hit_record &rec) const {
        return std::nullopt;
    }
private:

};


#endif //BASIC_RAYTRACING_MATERIAL_H
