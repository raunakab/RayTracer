project( src )

add_executable(
    main
    main.cpp
    ../includes/hit_record.h
    ../includes/hittable_list.h
    ../includes/hittable.h
    ../includes/init.h
    ../includes/ray.h
    ../includes/sphere.h
    ../includes/vec3_utils.h
    ../includes/vec3.h
    meta/init.cpp
    meta/ray.cpp
    # meta/vec3_utils.cpp
    meta/vec3.cpp
    objects/hit_record.cpp
    objects/hittable_list.cpp
    objects/hittable.cpp
    objects/sphere.cpp
)

target_include_directories( main PUBLIC
    ../includes/
)
target_link_libraries(
    main
    PRIVATE lib
)
