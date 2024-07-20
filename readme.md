## Compilation
If for some reason you can't/don't want to use CMake, G++ can be used

```g++ main.cpp hittable/hittable_list.cpp hittable/geometry/sphere.cpp hittable/material/emmisive.cpp hittable/material/lambertian.cpp hittable/material/metal.cpp raytracing/camera.cpp types/vec3.cpp utils/interval.cpp utils/utils.cpp -o pathtracer```

## Usage
Currently, the image is outputted to stdout in .ppm encoding. Most likely you want to save it to file like this

```./pathtracer > [your_file].ppm```