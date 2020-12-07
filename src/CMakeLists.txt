project( src )

add_executable(
    main
    main.cpp

    ../includes/hitRecord.h
    ../includes/hittable.h
    ../includes/hittableList.h

    ../includes/blackbody.h
    ../includes/blinn.h
    ../includes/dielectric.h
    ../includes/lambertian.h
    ../includes/material.h
    ../includes/metal.h

    ../includes/camera.h
    ../includes/light.h
    ../includes/pointLight.h
    ../includes/directionalLight.h
    ../includes/ray.h
    ../includes/vec3.h
    ../includes/vec3Utils.h

    ../includes/parallelepiped.h
    ../includes/triangle.h
    ../includes/sphere.h

    ../includes/raytracer.h

    hit/hitRecord.cpp
    hit/hittable.cpp
    hit/hittableList.cpp

    materials/blackbody.cpp
    materials/blinn.cpp
    materials/dielectric.cpp
    materials/lambertian.cpp
    materials/material.cpp
    materials/metal.cpp

    meta/camera.cpp
    meta/pointLight.cpp
    meta/directionalLight.cpp
    meta/light.cpp
    meta/ray.cpp
    meta/vec3.cpp
    meta/vec3Utils.cpp

    objects/parallelepiped.cpp
    objects/triangle.cpp
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
