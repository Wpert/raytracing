#ifndef VEC3_HPP
#define VEC3_HPP
#pragma once

#include "common_func.hpp"
#include <iostream>
#include <concepts>
#include <limits>
#include <cmath>

// template<typename T>
// concept NumericType = requires(T param)
// {
//     requires std::is_integral_v<T> || std::is_floating_point_v<T>;
//     requires !std::is_same_v<bool, T>;
//     requires std::is_arithmetic_v<decltype(param +1)>;
//     requires !std::is_pointer_v<T>;
// };
// template<typename T = double>

class vec3 {
public:
    double x;
    double y;
    double z;

    vec3() = default;
    vec3(double _x, double _y, double _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }
    template<typename U>
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
    // template<typename U>
    vec3(const vec3& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }
    // template<typename U>
    vec3 operator = (const vec3& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
        return *this;
    }

    inline vec3 operator -() const {
        return {-x, -y, -z};
    }
    inline double length_squared() const {
        return x*x + y*y + z*z;
    }
    inline double length() const {
        return sqrt(x * x + y * y + z * z);
    }
    // template<typename U>
    inline vec3 operator +(vec3 lhs) {
        return {x + lhs.x, y + lhs.y, z + lhs.z};
    }
    // template<typename U>
    inline vec3 operator +(vec3 lhs) const {
        return {x + lhs.x, y + lhs.y, z + lhs.z};
    }
    // template<typename U>
    inline vec3 operator -(vec3 lhs) {
        return {x - lhs.x, y - lhs.y, z - lhs.z};
    }
    // template<typename U>
    inline vec3 operator -(vec3 lhs) const {
        return {x - lhs.x, y - lhs.y, z - lhs.z};
    }
    template<typename U>
    inline vec3 operator *(U k) {
        return {x * k, y * k, z * k};
    }
    template<typename U>
    inline vec3 operator *(U k) const {
        return {x * k, y * k, z * k};
    }
    template<typename U>
    inline vec3 operator /(U k) {
        return {x / k, y / k, z / k};
    }
    template<typename U>
    inline vec3 operator /(U k) const {
        return {x / k, y / k, z / k};
    }

    // template<typename U>
    vec3& operator +=(vec3 rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    // template<typename U>
    vec3& operator -=(vec3 rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    template<typename U>
    vec3& operator *=(U k) {
        x *= k; y *= k; z *= k;
        return *this;
    }

};
// template<typename U>
std::ostream& operator<<(std::ostream& os, const vec3& v) {
      os << v.x << ' ' << v.y << ' ' << v.z;
      return os;
}

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
vec3 random_vec() {
    return {random_double(), random_double(), random_double()};
}

vec3 random_vec(double min, double max) {
    return {random_double(min, max), random_double(min, max), random_double(min, max)};
}

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

vec3 zero() {
    return {0, 0, 0};
}

using point3 = vec3;
using color = vec3;

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x) << ' '
        << static_cast<int>(255.999 * pixel_color.y) << ' '
        << static_cast<int>(255.999 * pixel_color.z) << '\n';
}

#endif