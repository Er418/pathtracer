#ifndef BASIC_RAYTRACING_INTERVAL_H
#define BASIC_RAYTRACING_INTERVAL_H


#include "utils.h"

class interval {
public:
    double min;
    double max;

    interval() : min(+infinity), max(-infinity) {} // Default interval is empty

    interval(double min, double max) : min(min), max(max) {}

    inline double size() const;

    inline bool contains(double x) const;

    inline bool surrounds(double x) const;

    double clamp(double x) const;

    static const interval empty, universe;
};


#endif //BASIC_RAYTRACING_INTERVAL_H
