#include "hittable.hpp"

bool sphere::hit(const ray& r, interval ray_t, hitted_surf& tangent_surf) const {
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
    tangent_surf.mat_ = this->mat_;

    vec3 outward_normal = ( tangent_surf.point_ - center_) / R_;
    tangent_surf.set_side_normal(r, outward_normal);

    return true;
}
