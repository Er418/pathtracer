#ifndef BASIC_RAYTRACING_CAMERA_H
#define BASIC_RAYTRACING_CAMERA_H

#include "../utils/utils.h"
#include "../types/types.h"
#include "../hittable/hittable_list.h"

class camera {
public:
    camera(int image_width, int image_height) :
            image_width(image_width), image_height(image_height),
            aspect_ratio(double(image_width) / image_height) {}

    camera(int image_width, double aspect_ratio) :
            image_width(image_width),
            image_height(std::max(1, int(image_width / aspect_ratio))),
            aspect_ratio(aspect_ratio) {}

    void render(hittable_list &world) {

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


    color ray_color(const ray &r, const hittable &world, int bounce = 0) const {
        auto k = world.hit(r, interval(0.001, infinity));

        if (k.has_value() && bounce < 20) {
            auto rec = k.value();
            vec3 new_direction = rec.normal + vec3::random_in_hemisphere(rec.normal);
            return 0.8 * ray_color(ray(rec.p, new_direction), world, bounce + 1);
        }

/*
        if (k.has_value() && bounce < 50) {
            auto rec = k.value();
            vec3 new_direction = vec3::unit_vector(r.get_direction());
            new_direction = new_direction - 2 * dot(new_direction, unit_vector(rec.normal)) * unit_vector(rec.normal);

            return 0.8 * ray_color(ray(rec.p, new_direction), world, bounce + 1) +
                   0.2 * 0.5 * (color(rec.normal.x(), rec.normal.y(), rec.normal.z()) + color(1, 1, 1));;
        }
*/
        vec3 unit_direction = unit_vector(r.get_direction());
        double t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
    }

    void set_sample_size(int k) {
        samples_per_pixel = k;
    }

    int get_sample_size() const {
        return samples_per_pixel;
    }

private:
    int image_width;
    int image_height;
    double aspect_ratio;
    point3 camera_origin;
    point3 viewport_upper_left;
    vec3 pixel_delta_horizontal;
    vec3 pixel_delta_vertical;

    int samples_per_pixel = 10;

    color sample_pixel(int x, int y, const hittable &world) {
        color pixel_color(0, 0, 0);
        for (int i = 0; i < samples_per_pixel; i++) {
            auto pixel_sample = get_pixel_sample(x, y);
            ray r(camera_origin, pixel_sample - camera_origin);
            pixel_color += ray_color(r, world) / samples_per_pixel;
        }
        return pixel_color;
    }

    point3 get_pixel_center(int x, int y) {
        return viewport_upper_left
               + (x + 0.5) * pixel_delta_horizontal
               + (y + 0.5) * pixel_delta_vertical;
    }

    point3 get_pixel_sample(int x, int y) {
        return viewport_upper_left
               + (x + random_double()) * pixel_delta_horizontal
               + (y + random_double()) * pixel_delta_vertical;
    }

    void initialize() {
        double focal_length = 1.0;
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
};


#endif //BASIC_RAYTRACING_CAMERA_H
