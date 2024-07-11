#include "hittable/sphere.h"
#include "hittable/hittable_list.h"
#include "raytracing/camera.h"


int main() {

    int image_width = 1920;
    int image_height = 1080;



    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, 1), 0.5));
    world.add(make_shared<sphere>(point3(0.5, 0, 1), 0.5));
    world.add(make_shared<sphere>(point3(-45, 45, 70), 2));
    world.add(make_shared<sphere>(point3(0, 55, 70), 2));
    world.add(make_shared<sphere>(point3(0, -100.5, 1), 100));

    camera cam(image_width, image_height);
    cam.set_sample_size(50);
    cam.render(world);

}