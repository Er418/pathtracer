cmake_minimum_required(VERSION 3.26)
project(basic_raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(basic_raytracing source/main.cpp
        source/types/vec3.h
        source/types/color.h
        source/types/ray.h
        source/hittable/hittable.h
        source/hittable/geometry/sphere.h
        source/hittable/hittable_list.h
        source/hittable/hittable_list.cpp
        source/hittable/geometry/sphere.cpp
        source/utils/utils.h
        source/raytracing/camera.cpp
        source/raytracing/camera.h
        source/utils/utils.cpp
        source/utils/interval.cpp
        source/utils/interval.h
        source/types/vec3.cpp
        source/types/types.h
        source/hittable/material/material.h
        source/hittable/material/metal.cpp
        source/hittable/material/metal.h
        source/hittable/material/materials.h
        source/hittable/material/lambertian.cpp
        source/hittable/material/lambertian.h
        source/hittable/material/emmisive.cpp
        source/hittable/material/emmisive.h
)
