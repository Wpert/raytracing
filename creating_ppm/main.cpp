#include <iostream>
#include <string>

int main() {
    int mask = 5;

    int rmask = mask & 1;
    int bmask = mask & 2;
    int gmask = mask & 4;

    ushort image_width = 256;
    ushort image_height = 256;

    std::cout << "P3\n" << image_width << ' ' << image_height << '\n' << 255 << std::endl;
    
    uint r = 0, g = 0, b = 0;
    for (ushort x = 0; x < image_height; ++x) {
        std::clog << "\r Scanlines remaining: " << (image_height - x) << std::flush;
        for (ushort y = 0; y < image_width; ++y) {
            if (rmask)
                r = static_cast<uint>(255.99 * x / double(image_height - 1));
            if (gmask)
                g = static_cast<uint>(255.99 * y / double(image_height - 1));
            if (bmask)
                b = static_cast<uint>(255.99 * y / double(image_height - 1));
            std::cout << r << ' ' << g << ' ' << b << '\n';
        }
    }

    std::clog << "\rDone!                       \n";
    return 0;
}