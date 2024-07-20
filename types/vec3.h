#ifndef BASIC_RAYTRACING_VEC3_H
#define BASIC_RAYTRACING_VEC3_H

#include <array>
#include <cmath>

#include "../utils/utils.h"

class vec3 {
public:
    vec3() : values{0.0, 0.0, 0.0} {};

    vec3(double x, double y, double z) : values{x, y, z} {};

    double x() const { return values[0]; };

    double y() const { return values[1]; };

    double z() const { return values[2]; };


    vec3 operator-() const { return {-values[0], -values[1], -values[2]}; }

    double operator[](int i) const { return values[i]; }

    double &operator[](int i) { return values[i]; }

    vec3 &operator+=(const vec3 &other) {
        values[0] += other.values[0];
        values[1] += other.values[1];
        values[2] += other.values[2];
        return *this;
    }

    vec3 &operator*=(double k) {
        values[0] *= k;
        values[1] *= k;
        values[2] *= k;
        return *this;
    }

    vec3 &operator/=(double k) {
        return *this *= 1 / k;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return values[0] * values[0] + values[1] * values[1] + values[2] * values[2];
    }

    static vec3 unit_vector(const vec3& vec);

    static vec3 random_raw() {
        return {random_double(), random_double(), random_double()};
    }

    static vec3 random_raw(double min, double max) {
        return {random_double(min, max), random_double(min, max), random_double(min, max)};
    }

    static vec3 random_uniform() {
        while (true) {
            vec3 buf = random_raw(-1.0, 1.0);
            if (buf.length_squared() <= 1.0) {
                return buf;
            }
        }
    }

    static vec3 random_unit() {
        return unit_vector(random_uniform());
    }

    static vec3 random_in_hemisphere(const vec3& normal);

    static vec3 reflect(const vec3& ray, const vec3& normal);

private:
    std::array<double, 3> values;
};

using point3 = vec3;

inline vec3 operator+(const vec3 &a, const vec3 &b) {
    return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z()};
}

inline vec3 operator-(const vec3 &a, const vec3 &b) {
    return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z()};
}

inline vec3 operator*(const vec3 &a, const vec3 &b) {
    return {a.x() * b.x(), a.y() * b.y(), a.z() * b.z()};
}

inline vec3 operator*(double k, const vec3 &a) {
    return {k * a.x(), k * a.y(), k * a.z()};
}

inline vec3 operator*(const vec3 &a, double k) {
    return k * a;
}

inline vec3 operator/(vec3 a, double k) {
    return (1 / k) * a;
}

inline double dot(const vec3 &a, const vec3 &b) {
    return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

inline vec3 cross(const vec3 &a, const vec3 &b) {
    return {a.y() * b.z() - a.z() * b.y(),
            a.z() * b.x() - a.x() * b.z(),
            a.x() * b.y() - a.y() * b.x()};
}

inline vec3 unit_vector(const vec3 &a) {
    return a / a.length();
}

#endif //BASIC_RAYTRACING_VEC3_H
