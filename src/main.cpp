#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <float.h>

#include <Logger/logger.h>

#include <camera.h>
#include <vec3.h>
#include <vec3_utils.h>
#include <ray.h>
#include <hittable.h>
#include <hittable_list.h>
#include <sphere.h>
#include <hit_record.h>

float hit_sphere(Vec3 const & center, float const radius, Ray const & r) {
    Vec3 const OtoC(r.origin() - center);
    Vec3 const P(r.direction());
    float const a(dot(OtoC, OtoC));
    float const b(dot(P, OtoC));
    float const discriminant(b*b - a*(dot(P, P) - (radius*radius)));

    // should it be >= ?
    if (discriminant > 0.0) {
        return (-b - sqrt(discriminant)) / a;
    } else {
        return -1.0;
    }
}

Vec3 colour(Ray const & r, Hittable * const world) {
    HitRecord hr;

    if (world->hit(r, 0.0, MAXFLOAT, hr)) {
        Vec3 & normal(hr.normal);
        normal += Vec3(1.0, 1.0, 1.0);

        return 0.5 * normal;
    } else {
        Vec3 dir(r.direction());
        dir.makeUnitVector();

        float const t(0.5 * (dir.y() + 1.0));

        return ((1.0 - t) * Vec3(1.0, 1.0, 1.0)) + (t * Vec3(0.5, 0.7, 1.0));
    }
}

void setup(int argc, char ** argv, std::ofstream & fs, int & nx, int & ny, int & ns) {
    if (argc != 5) Logger::error(std::string("incorrect number of arguments"), -1);

    try {
        nx = std::stoi(std::string(argv[2]));
    } catch (...) {
        Logger::error(std::string("invalid horizontal resolution"), -1);
    }
    try {
        ny = std::stoi(std::string(argv[3]));
    } catch (...) {
        Logger::error(std::string("invalid vertical resolution"), -1);
    }
    try {
        ns = std::stoi(std::string(argv[4]));
    } catch (...) {
        Logger::error(std::string("invalid aliasing degree"), -1);
    }

    fs.open("./../../out/" + std::string(argv[1]) + ".ppm");
    fs << "P3\n" << nx << " " << ny << "\n255\n";

    return;
}

int main(int argc, char ** argv) {
    std::ofstream fs;
    int nx;
    int ny;
    int ns;

    setup(argc, argv, fs, nx, ny, ns);
    srand48(time(0));

    int const length(2);
    Hittable * hl[length];
    hl[0] = new Sphere(Vec3(0.0, 0.0, -1.0), 0.5);
    hl[1] = new Sphere(Vec3(0.0, -100.5, -1.0), 100.0);


    Hittable * const world(new HittableList(hl, length));
    Camera camera;

    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        Vec3 col(0.0, 0.0, 0.0);
        for (int s(0); s<ns; ++s) {
            float u((float(i) + drand48()) / float(nx));
            float v((float(j) + drand48()) / float(ny));

            col += colour(camera.getRay(u,v), world);
        }
        col /= float(ns);

        col *= 255.99;
        fs << col;
    }

    delete world;

    fs.close();
    return 0;
}
