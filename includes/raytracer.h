#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <float.h>
#include <math.h>

#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <camera.h>
#include <hittable.h>
#include <vec3.h>
#include <ray.h>
#include <hitRecord.h>
#include <light.h>

class RayTracer {
private:
    RayTracer() = delete;
    RayTracer(RayTracer const &) = delete;
    RayTracer(RayTracer const &&) = delete;

    void operator=(RayTracer const &) = delete;
    void operator=(RayTracer const &&) = delete;

    Vec3 colour(Ray const &, int const) const;

public:
    std::string const filePath;
    Light const * const light;
    Camera const camera;
    Hittable const * const hittable;
    int const maxBounce;

    RayTracer(
        std::string const &&,
        Light const * const &&,
        Camera const &&,
        Hittable const * const &&,
        int const
    );
    ~RayTracer();

    void start(int const, int const, int const) const;
};

#endif
