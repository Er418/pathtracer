#include "camera.h"

void camera::render(hittable_list &world) {

    std::clog << "Rendering image of size " << image_width << "x" << image_height << std::endl;
    initialize();
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            color pixel_color = sample_pixel(i, j, world);
            display_rgb(pixel_color).write(std::cout);
        }
    }
    std::clog << "\rDone.                 \n";
}

color camera::ray_color(const ray &r, const hittable &world, int bounce) const {
    auto k = world.hit(r, interval(0.001, infinity));

    if (k.has_value() && bounce < bounce_limit) {
        hit_record ret = k.value();
        auto scatter = ret.mat->scatter(r, ret);
        if (scatter.has_value()) {
            color ret;
            for (const auto& i: scatter.value().get_rays()) {
                if (i.ray_value.has_value()) {
                    ret += ray_color(i.ray_value.value(), world, bounce + 1) * i.weight;
                } else if (i.color_value.has_value()) {
                    ret += i.color_value.value() * i.weight;
                }
            }
            return ret;
        }
    }


    vec3 unit_direction = unit_vector(r.get_direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

void camera::set_sample_size(int k) {
    samples_per_pixel = k;
}

int camera::get_sample_size() const {
    return samples_per_pixel;
}

color camera::sample_pixel(int x, int y, const hittable &world) {
    color pixel_color(0, 0, 0);
    for (int i = 0; i < samples_per_pixel; i++) {
        auto pixel_sample = get_pixel_sample(x, y);
        ray r(camera_origin, pixel_sample - camera_origin);
        pixel_color += ray_color(r, world) / samples_per_pixel;
    };
    return pixel_color;
}

point3 camera::get_pixel_center(int x, int y) {
    return viewport_upper_left
           + (x + 0.5) * pixel_delta_horizontal
           + (y + 0.5) * pixel_delta_vertical;
}

point3 camera::get_pixel_sample(int x, int y) {
    return viewport_upper_left
           + (x + random_double()) * pixel_delta_horizontal
           + (y + random_double()) * pixel_delta_vertical;
}

void camera::initialize() {
    double focal_length = 1.5;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width) / image_height);
    camera_origin = {0, 0, 0};
    vec3 camera_direction = {0, 0, 1};

    camera_direction = unit_vector(camera_direction) * focal_length;

    // currently only for {0, 0, x} camera direction
    vec3 viewport_horizontal = {viewport_width, 0, 0};
    vec3 viewport_vertical = {0, -viewport_height, 0};

    pixel_delta_horizontal = viewport_horizontal / image_width;
    pixel_delta_vertical = viewport_vertical / image_height;

    viewport_upper_left = camera_origin + camera_direction - viewport_horizontal / 2 - viewport_vertical / 2;
    std::clog << "VUL: " << viewport_upper_left.x() << ' ' << viewport_upper_left.x() << ' '
              << viewport_upper_left.z() << ' ' << std::endl;
}
