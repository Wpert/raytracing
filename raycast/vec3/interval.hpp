#ifndef INTERVAL_HPP
#define INTERVAL_HPP

#include "common_func.hpp"

class interval {
public:
    double min_;
    double max_;

    interval() : min_(+infty), max_(-infty) {}
    interval(double min, double max) : min_(min), max_(max) {}
    interval(std::initializer_list<double> l) {
        if (l.size() != 2)
            throw std::invalid_argument("length of init list must be 2");
        auto iter = l.begin();
        this->min_ = *iter;
        iter = std::next(iter);
        this->max_ = *(iter);
    }

    bool contains(double x) const {
        return (min_ <= x) && (x <= max_);
    }
    bool surrounds(double x) const {
        return min_ < x && x < max_;
    }

    const static interval empty, universe;
};


const static interval empty(+infty, -infty);
const static interval universe(-infty, +infty);

#endif