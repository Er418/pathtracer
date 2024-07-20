#include "hittable/geometry/sphere.h"
#include "hittable/material/materials.h"
#include "hittable/hittable_list.h"
#include "raytracing/camera.h"



int main() {

    int image_width = 1000;
    int image_height = 500;

    shared_ptr<material> material_ground = make_shared<lambertian>(color(0.7, 0.7, 0.0), 0.0);
    shared_ptr<material> material_far = make_shared<metal>(color(1, 0.0, 0.54));
    shared_ptr<material> material_right = make_shared<metal>(color(0.9, 0.9, 0.9), 0.0, 0.15);
    shared_ptr<material> material_left = make_shared<metal>(color(1, 0.54, 0), 0.0, 0.0);
    shared_ptr<material> material_back = make_shared<metal>(color(0.54, 1, 0), 0.0, 0.05);
    shared_ptr<material> material_big = make_shared<metal>(color(0.95, 0.95, 0.95), 0.0, 0.00);
    shared_ptr<material> material_center = make_shared<lambertian>(color(0.0, 0.0, 0.8), 0.0);
    shared_ptr<material> material_light = make_shared<emmisive>(color(1.0, 1.0, 0.2), 20);
    shared_ptr<material> material_dim_light = make_shared<emmisive>(color(1.0, 1.0, 1.0), 0.3);

    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, 3), 0.5, material_center));
    world.add(make_shared<sphere>(point3(1.2, 0, 3), 0.5, material_right));
    world.add(make_shared<sphere>(point3(-1.2, 0, 3), 0.5, material_left));
    world.add(make_shared<sphere>(point3(-0.5, 2, 4), 0.5, material_back));
    world.add(make_shared<sphere>(point3(0, -100.5, 1), 100, material_ground));
    // world.add(make_shared<sphere>(point3(0.0, 5.0, 2.0), 2, material_light));
    world.add(make_shared<sphere>(point3(5.0, 2.0, 3.0), 1, material_light));
    world.add(make_shared<sphere>(point3(15, 35, 120), 100, material_big));
    world.add(make_shared<sphere>(point3(0,  30, -100), 70, material_dim_light));

    camera cam(image_width, image_height);
    cam.set_sample_size(4096);
    cam.render(world);

}