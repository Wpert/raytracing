#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "../vec3/color.hpp"
#include "hittable.hpp"

class material {
public:
    ~material() = default;
    virtual bool scatter(
        const ray& r_in, const hitted_surf& rec,
        color& attenuation, ray& scattered
        ) const {
        return false;
    }
};

class lambertian : public material {
    color albedo_;
public:
    lambertian(const color& albedo) : albedo_(albedo) {}

    bool scatter(const ray& r_in, const hitted_surf& rec, color& attenuation, ray& scattered)
    const override {
        auto scatter_direction = rec.normal_ + random_unit_vector();

        if (scatter_direction.near_zero())
            scatter_direction = rec.normal_;

        scattered = ray(rec.point_, scatter_direction);
        attenuation = this->albedo_;
        return true;
    } 
};

#endif
