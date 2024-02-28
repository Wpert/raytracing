#include <iostream>
#include <concepts>
#include <limits>
#include <cmath>
#pragma once

template<typename T>
concept NumericType = requires(T param)
{
    requires std::is_integral_v<T> || std::is_floating_point_v<T>;
    requires !std::is_same_v<bool, T>;
    requires std::is_arithmetic_v<decltype(param +1)>;
    requires !std::is_pointer_v<T>;
};

template<NumericType T = double>
class vec3 {
public:
    T x;
    T y;
    T z;

    vec3() = default;
    vec3(T _x, T _y, T _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }
    template<NumericType U>
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
    template<NumericType U>
    vec3(const vec3<U>& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }
    template<NumericType U>
    vec3 operator = (const vec3<U>& rhs) {
        this->x = rhs.x;
        this->y = rhs.y;
        this->z = rhs.z;
    }

    inline vec3 operator -() const {
        return {-x, -y, -z};
    }

    inline double length() const {
        return sqrt(x * x + y * y + z * z);
    }
    template<NumericType U>
    inline vec3 operator +(vec3<U> lhs) {
        return {x + lhs.x, y + lhs.y, z + lhs.z};
    }
    template<NumericType U>
    inline vec3 operator +(vec3<U> lhs) const {
        return {x + lhs.x, y + lhs.y, z + lhs.z};
    }
    template<NumericType U>
    inline vec3 operator -(vec3<U> lhs) {
        return {x - lhs.x, y - lhs.y, z - lhs.z};
    }
    template<NumericType U>
    inline vec3 operator -(vec3<U> lhs) const {
        return {x - lhs.x, y - lhs.y, z - lhs.z};
    }
    template<NumericType U>
    inline vec3 operator *(U k) {
        return {x * k, y * k, z * k};
    }
    template<NumericType U>
    inline vec3 operator *(U k) const {
        return {x * k, y * k, z * k};
    }
    template<NumericType U>
    inline vec3 operator /(U k) {
        return {x / k, y / k, z / k};
    }
    template<NumericType U>
    inline vec3 operator /(U k) const {
        return {x / k, y / k, z / k};
    }

    template<NumericType U>
    vec3& operator +=(vec3<U> rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    template<NumericType U>
    vec3& operator -=(vec3<U> rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    template<NumericType U>
    vec3& operator *=(U k) {
        x *= k; y *= k; z *= k;
        return *this;
    }
};
template<NumericType U>
std::ostream& operator<<(std::ostream& os, const vec3<U>& v) {
      os << v.x << ' ' << v.y << ' ' << v.z;
      return os;
}

template<NumericType U, NumericType V>
inline double dot(const vec3<U>& rhs, const vec3<V> lhs) {
    return static_cast<double> (rhs.x * lhs.x +
                                rhs.y * lhs.y +
                                rhs.z * lhs.z);
}

template<NumericType U, NumericType V>
inline vec3<double> cross(const vec3<U>& rhs, const vec3<V>& lhs) {
    return vec3(rhs.y * lhs.z - rhs.z * lhs.y,
                rhs.z * lhs.x - rhs.x * lhs.z,
                rhs.x * lhs.y - rhs.y * lhs.x);
}

template<NumericType U, NumericType V>
inline vec3<double> operator *(V k, const vec3<U> v) {
    return v * k;
}

template<NumericType U>
inline vec3<double> unit_vector(vec3<U> v) {
    return v / v.length();
}

template<NumericType U, NumericType V>
inline double distance(vec3<U> rhs, vec3<V> lhs) {
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

using point3 = vec3<double>;