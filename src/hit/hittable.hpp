#ifndef HITTABLE_HPP
#define HITTABLE_HPP
#pragma once

#include "../vec3/interval.hpp"
#include "../vec3/ray.hpp"

class material;

struct hitted_surf {
    point3 point_;
    vec3 normal_;
    shared_ptr<material> mat_;
    double t_;
    bool front_side_;

    void set_side_normal(const ray& r, const vec3& outward_normal) {
        // Sets the hit record normal vector.
        // NOTE: the parameter `outward_normal` is assumed to have unit length.
        front_side_ = dot(r.direction(), outward_normal) < 0.0;
        normal_ = front_side_ ? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;
    virtual bool hit(const ray& r, interval ray_t, hitted_surf& tangent_surf) const = 0;
};

class sphere : public hittable {
   point3 center_;
   double R_; 
   shared_ptr<material> mat_;
public:
    sphere(const point3& center, double r, shared_ptr<material> mat) : center_(center), R_(r) {
        this->mat_ = mat;
    }

    bool hit(const ray& r, interval ray_t, hitted_surf& tangent_surf) const override;
};

#endif