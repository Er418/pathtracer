#ifndef BASIC_RAYTRACING_INTERVAL_H
#define BASIC_RAYTRACING_INTERVAL_H


#include "utils.h"

class interval {
public:
    double min;
    double max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double min, double max) : min(min), max(max) {}

    inline double size() const {
        return max - min;
    }

    inline bool contains(double x) const {
        return min <= x && x <= max;
    }

    inline bool surrounds(double x) const {
        return min < x && x < max;
    }

    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};


#endif //BASIC_RAYTRACING_INTERVAL_H
