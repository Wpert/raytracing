#ifndef COLOR_HPP
#define COLOR_HPP

#include "interval.hpp"
#include "vec3.hpp"

using color = vec3;

inline double linear_to_gamma(double linear_componenr) {
    return (linear_componenr > 0) ? sqrt(linear_componenr) : 0;
}

void write_color(std::ostream &out, color pixel_color) {
    // Write the translated [0,255] value of each color component.
    auto r = pixel_color.x;
    auto g = pixel_color.y;
    auto b = pixel_color.z;

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const interval intensity{0.000, 0.999};
    out << static_cast<int>(256 * intensity.clamp(r)) << ' '
        << static_cast<int>(256 * intensity.clamp(g)) << ' '
        << static_cast<int>(256 * intensity.clamp(b)) << '\n';
}

#endif
