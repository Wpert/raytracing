#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include "common_func.hpp"

class interval {
public:
    double min_;
    double max_;

    interval();
    interval(double min, double max);
    interval(std::initializer_list<double> l);

    bool contains(double x) const;
    bool surrounds(double x) const;
    double clamp(double x) const;

    const static interval empty, universe;
};


const static interval empty(+infty, -infty);
const static interval universe(-infty, +infty);

#endif