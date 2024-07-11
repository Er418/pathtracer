#ifndef BASIC_RAYTRACING_UTILS_H
#define BASIC_RAYTRACING_UTILS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <random>


using std::make_shared;
using std::shared_ptr;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

double degrees_to_radians(double degrees);

inline std::random_device rd;
inline std::mt19937 rng(rd());
inline std::uniform_real_distribution<double> standard_uniform_distribution(0.0, 1.0);

double random_double();

double random_double(double min, double max);

#endif //BASIC_RAYTRACING_UTILS_H
