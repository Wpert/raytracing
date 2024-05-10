#ifndef COMMON_FUNC_HPP
#define COMMON_FUNC_HPP
#pragma once
// stl headers

#include <memory>
#include <vector>
#include <cmath>
#include <limits>
#include <random>

// constants

const double infty = std::numeric_limits<double>::infinity();

// usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// functions

inline double degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {
    // Returns a random real in [min,max).
    return min + (max - min) * random_double();
}

#endif