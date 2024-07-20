#include "hittable/geometry/sphere.h"
#include "hittable/material/materials.h"
#include "hittable/hittable_list.h"
#include "raytracing/camera.h"



int main() {

    int image_width = 1920;
    int image_height = 1080;

    shared_ptr<material> material_ground = make_shared<lambertian>(color(0.7, 0.7, 0.0), 0.5);
    shared_ptr<material> material_far = make_shared<metal>(color(1, 0.0, 0.54));
    shared_ptr<material> material_right = make_shared<metal>(color(1, 0.54, 0), 0.9, 0.15);
    shared_ptr<material> material_left = make_shared<metal>(color(1, 0.54, 0), 0.6, 0.0);
    shared_ptr<material> material_back = make_shared<metal>(color(1, 0.54, 0), 0.7, 0.05);
    shared_ptr<material> material_center = make_shared<lambertian>(color(0.0, 0.0, 0.8), 0.8);

    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, 3), 0.5, material_center));
    world.add(make_shared<sphere>(point3(1.2, 0, 3), 0.5, material_right));
    world.add(make_shared<sphere>(point3(-1.2, 0, 3), 0.5, material_left));
    world.add(make_shared<sphere>(point3(-0.5, 2, 4), 0.5, material_back));
    world.add(make_shared<sphere>(point3(-45, 45, 70), 2, material_far));
    world.add(make_shared<sphere>(point3(0, 55, 70), 2, material_far));
    world.add(make_shared<sphere>(point3(0, -100.5, 1), 100, material_ground));

    camera cam(image_width, image_height);
    cam.set_sample_size(512);
    cam.render(world);

}