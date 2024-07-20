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

vec3 vec3::reflect(const vec3 &ray, const vec3 &normal) {
    vec3 ret = unit_vector(ray);
    ret = ret - 2 * dot(ret, unit_vector(normal)) * unit_vector(normal);
    return ret;
}
