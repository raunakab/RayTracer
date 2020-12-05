#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <float.h>
#include <math.h>

#include <Logger/logger.h>

#include <camera.h>
#include <vec3.h>
#include <vec3Utils.h>
#include <ray.h>
#include <hittable.h>
#include <hittableList.h>
#include <sphere.h>
#include <hitRecord.h>
#include <lambertian.h>
#include <metal.h>
#include <dielectric.h>

int const maxDepth = 50;

Vec3 colour(Ray const & r, Hittable const * const world, int const depth) {
    HitRecord record;

    if (world->hit(r, 0.001, MAXFLOAT, record)) {
        Ray scattered(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 0.0, 0.0));
        Vec3 attenuation(0.0, 0.0, 0.0);

        if (depth < maxDepth && record.material && record.material->scatter(r, record, attenuation, scattered))
            return attenuation * colour(scattered, world, depth+1);
        else return Vec3(0.0, 0.0, 0.0);
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

    float const radius(0.2);
    int const length(36);
    int const range(sqrt(length) / 2);
    Hittable * hittableList[length + 1];

    int count(0);
    hittableList[count++] = new Sphere(Vec3(0.0, -1000.0, 0.0),   1000.0, new Lambertian(Vec3(0.5, 0.5, 0.5)));

    for (int a(-range); a<range; ++a) for (int b(-range); b<range; ++b) {
        float const randomizedMaterial(drand48());
        Vec3 centre(a+(0.9*drand48()), radius, b+(0.9*drand48()));

        if ((centre - Vec3(4.0, 0.2, 0.0)).length() > 0.9) {
            if (randomizedMaterial < 0.5) {
                hittableList[count++] = new Sphere(centre, radius,
                    new Lambertian(Vec3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()))
                );
            } else if (randomizedMaterial < 0.8) {
                hittableList[count++] = new Sphere(centre, radius,
                    new Metal(
                        Vec3(0.5 * (1 + drand48()), 0.5 * (1.0 + drand48()), 0.5 * (1.0 + drand48())),
                        0.5 * drand48()
                    )
                );
            } else {
                hittableList[count++] = new Sphere(centre, radius, new Dielectric(1.5));
            }
        }
    }
    // hl[1] = new Sphere(Vec3(0.0, -100.5, -1.0), 100.0, new Lambertian(Vec3(0.8, 0.8, 0.0)));
    // hl[2] = new Sphere(Vec3(1.0, 0.0, -1.0),      0.5, new Metal(Vec3(0.8, 0.6, 0.2), 0.2));
    // hl[3] = new Sphere(Vec3(-1.0, 0.0, -1.0),     0.5, new Dielectric(1.5));
    // hl[4] = new Sphere(Vec3(-1.0, 0.0, -1.0),   -0.45, new Dielectric(1.5));

    Hittable const * const world(new HittableList(hittableList, count));

    Vec3 lookFrom(3.0, 3.0, 2.0);
    Vec3 lookAt(0.0, 0.0, -1.0);
    Vec3 up(0.0, 1.0, 0.0);
    float distanceToFocus((lookAt - lookFrom).length());
    float aperture(1.0);
    Camera camera(lookFrom, lookAt, up, M_PI / 9, float(nx) / float(ny), aperture, distanceToFocus);

    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        Vec3 col(0.0, 0.0, 0.0);
        for (int s(0); s<ns; ++s) {
            float u((float(i) + drand48()) / float(nx));
            float v((float(j) + drand48()) / float(ny));

            col += colour(camera.getRay(u,v), world, 0);
        }
        col /= float(ns);

        col.e[0] = sqrt(col.e[0]);
        col.e[1] = sqrt(col.e[1]);
        col.e[2] = sqrt(col.e[2]);

        col *= 255.99;
        fs << col;
    }

    delete world;

    fs.close();
    return 0;
}
