project( src )

add_executable(
    main
    main.cpp
    ../includes/camera.h

    ../includes/hitRecord.h
    ../includes/hittable.h
    ../includes/hittableList.h

    ../includes/dielectric.h
    ../includes/lambertian.h
    ../includes/material.h
    ../includes/metal.h

    ../includes/ray.h
    ../includes/sphere.h
    ../includes/vec3.h
    ../includes/vec3Utils.h

    ../includes/raytracer.h

    hit/hitRecord.cpp
    hit/hittable.cpp
    hit/hittableList.cpp

    materials/dielectric.cpp
    materials/lambertian.cpp
    materials/material.cpp
    materials/metal.cpp

    meta/camera.cpp
    meta/ray.cpp
    meta/vec3.cpp
    meta/vec3Utils.cpp

    objects/sphere.cpp

    raytracer/raytracer.cpp
)

target_include_directories( main PUBLIC
    ../includes/
)
target_link_libraries(
    main
    PRIVATE lib
)
