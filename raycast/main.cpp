#include "cam/camera.hpp"
#include "hit/hittable_list.hpp"
#include <iostream>

int main() {
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 10;
    cam.max_depth = 20;

    cam.render(world);
}