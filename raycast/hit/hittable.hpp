#ifndef HITTABLE_HPP
#define HITTABLE_HPP
#pragma once

#include "../vec3/vec3.hpp"
#include "../vec3/ray.hpp"

struct hitted_surf {
    point3 point_;
    vec3 normal_;
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
public:
    sphere(point3 center, double r) : center_(center), R_(r) {}

    bool hit(const ray& r, interval ray_t, hitted_surf& tangent_surf) const override {
        vec3 oc = r.origin() - center_;
        auto A = dot(r.direction(), r.direction());
        auto B = dot(oc, r.direction());
        auto C = dot(oc, oc) - R_ * R_;
        auto D = B * B - A * C;    
        if (D < 0)
            return false;
        // save one sqrt(double) call
        auto sqrtD = sqrt(D);

        auto root = ( -B - sqrtD ) / A;
        // decide which root do we need
        if (root <= ray_t.min_ || root >= ray_t.max_) {
            root = ( -B + sqrtD ) / A;
            if (root <= ray_t.min_ || root >= ray_t.max_)
                return false;
        }

        tangent_surf.t_ = root; // t
        tangent_surf.point_ = r.at(root);
        tangent_surf.normal_ = ( tangent_surf.point_ - this->center_ ) / R_;
        
        vec3 outward_normal = ( tangent_surf.point_ - center_) / R_;
        tangent_surf.set_side_normal(r, outward_normal);

        return true;
    }
};

#endif