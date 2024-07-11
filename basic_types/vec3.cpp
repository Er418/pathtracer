#include "vec3.h"

vec3 vec3::unit_vector(const vec3 &vec) {
    return vec / vec.length();
}

vec3 vec3::random_in_hemisphere(const vec3 &normal) {
    vec3 buf = random_unit();
    if (dot(buf, normal) < 0) {
        return -buf;
    } else {
        return buf;
    }
}