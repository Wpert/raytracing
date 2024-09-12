#include "vec3.hpp"

vec3::vec3(double _x, double _y, double _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
}

vec3::vec3(const vec3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
}

vec3 vec3::operator = (const vec3& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    return *this;
}

vec3& vec3::operator +=(vec3 rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

vec3& vec3::operator -=(vec3 rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

template<typename U>
vec3& vec3::operator *=(U k) {
    x *= k; y *= k; z *= k;
    return *this;
}

vec3 zero() {
    return {0, 0, 0};
}

std::ostream& operator<<(std::ostream& os, const vec3& v) {
      os << v.x << ' ' << v.y << ' ' << v.z;
      return os;
}

vec3 random_vec() {
    return {random_double(), random_double(), random_double()};
}

vec3 random_vec(double min, double max) {
    return {random_double(min, max), random_double(min, max), random_double(min, max)};
}
