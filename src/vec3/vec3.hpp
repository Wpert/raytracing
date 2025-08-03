#ifndef VEC3_HPP
#define VEC3_HPP
#pragma once

#include "common_func.hpp"
#include <iostream>
#include <concepts>
#include <limits>
#include <cmath>

class vec3 {
public:
    double x;
    double y;
    double z;

    vec3() = default;
    vec3(double _x, double _y, double _z);
 
    template<typename U = double>
    vec3(std::initializer_list<U> l) {
        if (l.size() != 3)
            throw std::invalid_argument("length of init list must be 3");
        auto iter = l.begin();
        this->x = *iter;
        iter = std::next(iter);
        this->y = *(iter);
        iter = std::next(iter);
        this->z = *(iter);
    }

    vec3(const vec3& rhs);
    vec3 operator = (const vec3& rhs);

    inline vec3 operator -() const {
        return {-x, -y, -z};
    }
    inline double length_squared() const {
        return x*x + y*y + z*z;
    }
    inline double length() const {
        return sqrt(x * x + y * y + z * z);
    }
    inline vec3 operator +(vec3 lhs) {
        return {x + lhs.x, y + lhs.y, z + lhs.z};
    }
    inline vec3 operator +(vec3 lhs) const {
        return {x + lhs.x, y + lhs.y, z + lhs.z};
    }
    inline vec3 operator -(vec3 lhs) {
        return {x - lhs.x, y - lhs.y, z - lhs.z};
    }
    inline vec3 operator -(vec3 lhs) const {
        return {x - lhs.x, y - lhs.y, z - lhs.z};
    }
    template<typename U = double>
    inline vec3 operator *(U k) {
        return {x * k, y * k, z * k};
    }
    template<typename U = double>
    inline vec3 operator *(U k) const {
        return {x * k, y * k, z * k};
    }
    template<typename U = double>
    inline vec3 operator /(U k) {
        return {x / k, y / k, z / k};
    }
    template<typename U = double>
    inline vec3 operator /(U k) const {
        return {x / k, y / k, z / k};
    }
    vec3& operator +=(vec3 rhs);
    vec3& operator -=(vec3 rhs);
    template<typename U>
    vec3& operator *=(U k);
    bool near_zero() const {
        // Return true if the vector is close to zero in all dimensions.
        auto s = 1e-8;
        return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
    }
};
// template<typename U>
std::ostream& operator<<(std::ostream& os, const vec3& v);

// template<typename U, typename V>
inline double dot(const vec3& rhs, const vec3& lhs) {
    return static_cast<double> (rhs.x * lhs.x +
                                rhs.y * lhs.y +
                                rhs.z * lhs.z);
}

// template<typename U, typename V>
inline vec3 cross(const vec3& rhs, const vec3& lhs) {
    return vec3(rhs.y * lhs.z - rhs.z * lhs.y,
                rhs.z * lhs.x - rhs.x * lhs.z,
                rhs.x * lhs.y - rhs.y * lhs.x);
}

// template<typename U, typename V>
template <typename V>
inline vec3 operator *(V k, const vec3 v) {
    return v * k;
}

// template<typename U>
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

// template<typename U, typename V>
inline double distance(vec3 rhs, vec3 lhs) {
    return sqrt((rhs.x - lhs.x) * (rhs.x - lhs.x) + 
                (rhs.y - lhs.y) * (rhs.y - lhs.y) +
                (rhs.z - lhs.z) * (rhs.z - lhs.z)); 
}

// approximatelyEqual
bool inline apprEq(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
    return std::abs(a - b) <= (std::max(std::abs(b), std::abs(a)) * epsilon);
}
// essentiallyEqual
bool inline essEq(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
    return std::abs(a - b) <= (std::min(std::abs(b), std::abs(a)) * epsilon);
}
// definitelyGreaterThan
bool inline dGreaterT(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
    return (a - b) > (std::max(std::abs(b), std::abs(a)) * epsilon);
}
// definitelyLessThan
bool inline dLessT(double a, double b, double epsilon = std::numeric_limits<double>::epsilon()) {
    return (b - a) > (std::max(std::abs(b), std::abs(a)) * epsilon);
}

vec3 random_vec();

vec3 random_vec(double min, double max);

inline vec3 random_in_unit_sphere() {
    while (true) {
        auto p = random_vec(-1, 1);
        if (p.length_squared() < 1)
            return p;
    }
}

inline const vec3 random_unit_vector() {
    return unit_vector(random_in_unit_sphere());
}

inline vec3 random_on_hemisphere(const vec3& normal) {
    auto on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0)
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2 * dot(v, n) * n;
}

vec3 zero();

using point3 = vec3;

#endif