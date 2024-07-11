#include "utils.h"

double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

double random_double() {
    return standard_uniform_distribution(rng);
}

double random_double(double min, double max) {
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(rng);
}