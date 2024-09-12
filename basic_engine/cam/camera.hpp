#ifndef CAMERA_HPP
#define CAMERA_HPP
#pragma once

#include "../vec3/interval.hpp"
#include "../vec3/color.hpp"
#include "../hit/hittable.hpp"

class camera {
    int image_height;
    point3 center_;

    point3 pixel00_loc; // location of zeroth pixel
    vec3 pixel_delta_u;  // Offset to pixel to the right
    vec3 pixel_delta_v;  // Offset to pixel below
    double pixel_samples_scale;

    vec3 sample_square() const {
        return vec3(random_double() - 0.5, random_double() - 0.5, 0.0);
    }

    ray get_ray(int i, int j) const {
        auto offset = sample_square();
        auto pixel_sample = pixel00_loc
                          + (i + offset.x) * pixel_delta_u
                          + (j + offset.y) * pixel_delta_v;
        auto ray_origin = center_;
        auto ray_direction = pixel_sample - ray_origin;

        return ray(ray_origin, ray_direction); 
    }

public:
    double aspect_ratio = 1.0;  // Ratio of image width over height (width / height)
    int    image_width  = 100;  // Rendered image width in pixel count
    int    samples_per_pixel = 10;
    int    max_depth = 10;

    void render(const hittable& world) {
        initialize();

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; ++j) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for (int i = 0; i < image_width; ++i) {
                color pixel_color{0,0,0};
                
                for (int sample = 0; sample < samples_per_pixel; ++sample) {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, world, max_depth);
                }

                write_color(std::cout, pixel_color * pixel_samples_scale);
            }
        }

        std::clog << "\rDone.                 \n";
    }

private:
    void initialize() {
        image_height = static_cast<int>(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;
        pixel_samples_scale = 1.0 / samples_per_pixel;

        center_ = point3(0, 0, 0);

        // Determine viewport dimensions.
        auto focal_length = 1.0;
        auto viewport_height = 2.0;
        auto viewport_width = viewport_height * (static_cast<double>(image_width)/image_height);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        auto viewport_u = vec3(viewport_width, 0, 0);
        auto viewport_v = vec3(0, -viewport_height, 0);

        // Calculate the horizontal and vertical delta vectors from pixel to pixel.
        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Calculate the location of the upper left pixel.
        auto viewport_upper_left = center_ - vec3(0.0, 0.0, focal_length)
                                   - viewport_u / 2 - viewport_v / 2;
        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    }

    color ray_color(const ray& r, const hittable& world, int current_depth) const {
        hitted_surf rec;

        // если очень много отражений, то цвет ставим черный
        if (current_depth <= 0)
            return color(0,0,0);

        // если найден объект, то вычисляем его цвет след образом:
        // при коллизии с объектом говорим, что его цвет равен
        // половине цвета следующего рандомного отраженного луча
        if (world.hit(r, interval(0.001, infty), rec)) {
            ray scattered;
            color attenuation;
            if (rec.mat_->scatter(r, rec, attenuation, scattered))
                return attenuation * ray_color(scattered, world, current_depth - 1);
            return color(0,0,0);
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }
};

#endif