#include "interval.hpp"

interval::interval() : min_(+infty), max_(-infty) {}
interval::interval(double min, double max) : min_(min), max_(max) {}
interval::interval(std::initializer_list<double> l) {
    if (l.size() != 2)
        throw std::invalid_argument("length of init list must be 2");
    auto iter = l.begin();
    this->min_ = *iter;
    iter = std::next(iter);
    this->max_ = *(iter);
}

bool interval::contains(double x) const {
    return (min_ <= x) && (x <= max_);
}
bool interval::surrounds(double x) const {
    return min_ < x && x < max_;
}

double interval::clamp(double x) const {
    return (x < min_) ? min_ : (x > max_) ? max_ : x;
}