cmake_minimum_required(VERSION 3.26)
project(basic_raytracing)

set(CMAKE_CXX_STANDARD 20)

add_executable(basic_raytracing main.cpp
        basic_types/vec3.h
        basic_types/color.h
        basic_types/ray.h
        hittable/hittable.h
        hittable/sphere.h
        hittable/hittable_list.h
        hittable/hittable_list.cpp
        hittable/sphere.cpp
        utils/utils.h
        raytracing/camera.cpp
        raytracing/camera.h
        utils/utils.cpp
        utils/interval.cpp
        utils/interval.h
        basic_types/vec3.cpp
        basic_types/types.h
        hittable/material/material.cpp
        hittable/material/material.h
)
