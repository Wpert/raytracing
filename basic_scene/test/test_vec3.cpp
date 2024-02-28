#include "../vec3/vec3.hpp"
#include <cassert>
#include <iostream>
#include <cstdlib>

bool construction_test() {
    for (uint i = 0; i < 100; ++i) {
        int x = std::rand() % 256;
        int y = std::rand() % 256;
        int z = std::rand() % 256;

        vec3<int> v1 = {x, y, z};
        vec3<double> v2(x, y, z);
        vec3<short> v3(v2);
        if (!apprEq(v1.x, x) || !apprEq(v1.y, y) || !apprEq(v1.z, z))
            return false;
        if (!apprEq(v2.x, x) || !apprEq(v2.y, y) || !apprEq(v2.z, z))
            return false;
        if (!apprEq(v3.x, x) || !apprEq(v3.y, y) || !apprEq(v3.z, z))
            return false;
    }
    return true;
}

bool scalar_test() {
    int x = std::rand() % 256;
    int y = std::rand() % 256;
    int z = std::rand() % 256;
    auto v = vec3<double>(x, y, z);

    for (uint i = 0; i < 100; ++i) {
        int k = std::rand() % 256;

        auto u = v / k;
        if (!apprEq(u.x, v.x / k) || !apprEq(u.y, v.y / k) || !apprEq(u.z, v.z / k))
            return false;
        u = v * k;
        if (!apprEq(u.x, v.x * k) || !apprEq(u.y, v.y * k) || !apprEq(u.z, v.z * k))
            return false;
        u = -v;
        if (!apprEq(u.x, -v.x) || !apprEq(u.y, -v.y) || !apprEq(u.z, -v.z))
            return false;
        double l = v.length();
        if (!apprEq(l, sqrt(v.x * v.x + v.y * v.y + v.z * v.z)))
            return false;
    }
    return true;
}

bool vector_test() {
    return true;
}

int main() {
    assert(construction_test());
    assert(scalar_test());
    return 0;
}