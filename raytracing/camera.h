#ifndef BASIC_RAYTRACING_CAMERA_H
#define BASIC_RAYTRACING_CAMERA_H

#include "../utils/utils.h"
#include "../types/types.h"
#include "../hittable/hittable_list.h"
#include "../hittable/material/materials.h"

class camera {
public:
    camera(int image_width, int image_height) :
            image_width(image_width), image_height(image_height),
            aspect_ratio(double(image_width) / image_height) {}

    camera(int image_width, double aspect_ratio) :
            image_width(image_width),
            image_height(std::max(1, int(image_width / aspect_ratio))),
            aspect_ratio(aspect_ratio) {}

    void render(hittable_list &world);


    color ray_color(const ray &r, const hittable &world, int bounce = 0) const;

    void set_sample_size(int k);

    int get_sample_size() const;

    void set_bounce_limit(int k);

    int get_bounce_limit() const;

private:
    int image_width;
    int image_height;
    double aspect_ratio;
    point3 camera_origin;
    point3 viewport_upper_left;
    vec3 pixel_delta_horizontal;
    vec3 pixel_delta_vertical;

    int samples_per_pixel = 256;
    int bounce_limit = 20;

    color sample_pixel(int x, int y, const hittable &world);

    point3 get_pixel_center(int x, int y);

    point3 get_pixel_sample(int x, int y);

    void initialize();
};


#endif //BASIC_RAYTRACING_CAMERA_H
