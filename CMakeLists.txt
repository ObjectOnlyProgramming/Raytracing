cmake_minimum_required(VERSION 3.30.0 FATAL_ERROR)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
set(CMAKE_CXX_MODULE_STD ON)

set(CMAKE_CXX_SCAN_FOR_MODULES ON)

project(ObjectOnlyRaytracer
  LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_CXX_EXTENSIONS ON)

# find_package(glfw3 REQUIRED)

add_executable(ObjectOnlyRaytracer)

# target_link_libraries(ProjectName glfw)

target_sources(

    ObjectOnlyRaytracer
    PRIVATE
        Module_Implementations/Interval-IMPL.cpp
        Module_Implementations/Vector3D-IMPL.cpp
        Module_Implementations/Randomizer-IMPL.cpp
        Module_Implementations/Color-IMPL.cpp
        Module_Implementations/Ray-IMPL.cpp
        Module_Implementations/Hittable-IMPL/HitRecord-IMPL.cpp
        Module_Implementations/Material-IMPL/Lambertian-IMPL.cpp
        Module_Implementations/Material-IMPL/Metal-IMPL.cpp
        Module_Implementations/Material-IMPL/Dielectric-IMPL.cpp
        Module_Implementations/Hittable-IMPL/HittableList-IMPL.cpp
        Module_Implementations/Hittable-IMPL/Sphere-IMPL.cpp
        Module_Implementations/Camera-IMPL.cpp
        Module_Implementations/Raytracer-IMPL.cpp

    PUBLIC
    FILE_SET custom_modules TYPE CXX_MODULES
    FILES
        Module_Interfaces/Interval.cppm
        Module_Interfaces/Vector3D.cppm
        Module_Interfaces/Randomizer.cppm
        Module_Interfaces/Color.cppm
        Module_Interfaces/Ray.cppm
        Module_Interfaces/Hittable/HitRecord.cppm
        Module_Interfaces/Hittable/Hittable.cppm
        Module_Interfaces/Material/Lambertian.cppm
        Module_Interfaces/Material/Metal.cppm
        Module_Interfaces/Material/Dielectric.cppm
        Module_Interfaces/Hittable/HittableList.cppm
        Module_Interfaces/Material/Material.cppm
        Module_Interfaces/Hittable/Sphere.cppm
        Module_Interfaces/Camera.cppm
        Module_Interfaces/Raytracer.cppm

)

target_sources(ObjectOnlyRaytracer
  PRIVATE
    src/main.cpp
)