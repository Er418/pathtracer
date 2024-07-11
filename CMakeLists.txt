cmake_minimum_required(VERSION 3.26)
project(basic_raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(basic_raytracing main.cpp
        types/vec3.h
        types/color.h
        types/ray.h
        hittable/hittable.h
        hittable/geometry/sphere.h
        hittable/hittable_list.h
        hittable/hittable_list.cpp
        hittable/geometry/sphere.cpp
        utils/utils.h
        raytracing/camera.cpp
        raytracing/camera.h
        utils/utils.cpp
        utils/interval.cpp
        utils/interval.h
        types/vec3.cpp
        types/types.h
        hittable/material/material.cpp
        hittable/material/material.h
)
