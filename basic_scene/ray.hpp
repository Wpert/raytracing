#include "vec3/vec3.hpp"
#pragma once

class ray {
  public:
    ray() {}

    ray(const point3& origin, const vec3<double>& direction) : orig_(origin), dir_(direction) {}

    point3 origin() const  { return orig_; }
    vec3<double> direction() const { return dir_; }

    point3 at(double t) const {
        return orig_ + t * dir_;
    }

  private:
    point3 orig_;
    vec3<double> dir_;
};