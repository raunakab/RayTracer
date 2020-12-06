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
#include <raytracer.h>
#include <triangle.h>
#include <parallelepiped.h>

void setup(int argc, char ** argv, std::string & filePath, int & nx, int & ny, int & ns) {
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

    filePath = "./../../out/" + std::string(argv[1]);

    return;
}

int main(int argc, char ** argv) {
    std::string filePath;
    int nx;
    int ny;
    int ns;

    setup(argc, argv, filePath, nx, ny, ns);
    srand48(time(0));

    // int x[10];

    // float const radius(0.2);
    // int const length(36);
    // int const range(sqrt(length) / 2);
    // Hittable * hittableList[length + 1];

    // int count(0);
    // hittableList[count++] = new Sphere(Vec3(0.0, -1000.0, 0.0),   1000.0, new Lambertian(Vec3(0.5, 0.5, 0.5)));

    // for (int a(-range); a<range; ++a) for (int b(-range); b<range; ++b) {
    //     float const randomizedMaterial(drand48());
    //     Vec3 centre(a+(0.9*drand48()), radius, b+(0.9*drand48()));

    //     if ((centre - Vec3(4.0, 0.2, 0.0)).length() > 0.9) {
    //         if (randomizedMaterial < 0.5) {
    //             hittableList[count++] = new Sphere(centre, radius,
    //                 new Lambertian(Vec3(drand48()*drand48(), drand48()*drand48(), drand48()*drand48()))
    //             );
    //         } else if (randomizedMaterial < 0.8) {
    //             hittableList[count++] = new Sphere(centre, radius,
    //                 new Metal(
    //                     Vec3(0.5 * (1 + drand48()), 0.5 * (1.0 + drand48()), 0.5 * (1.0 + drand48())),
    //                     0.5 * drand48()
    //                 )
    //             );
    //         } else {
    //             hittableList[count++] = new Sphere(centre, radius, new Dielectric(1.5));
    //         }
    //     }
    // }
    // hl[1] = new Sphere(Vec3(0.0, -100.5, -1.0), 100.0, new Lambertian(Vec3(0.8, 0.8, 0.0)));
    // hl[2] = new Sphere(Vec3(1.0, 0.0, -1.0),      0.5, new Metal(Vec3(0.8, 0.6, 0.2), 0.2));
    // hl[3] = new Sphere(Vec3(-1.0, 0.0, -1.0),     0.5, new Dielectric(1.5));
    // hl[4] = new Sphere(Vec3(-1.0, 0.0, -1.0),   -0.45, new Dielectric(1.5));

    int const count(3);
    Hittable ** list = new Hittable*[count];

    // hittableList[0] = new Triangle(Vec3(-0.5, 0.5, -2.0), Vec3(0.5, 0.5, -2.0), Vec3(0.0, -0.5, -2.0), new Lambertian(Vec3(0.5, 0.5, 0.5)));
    // hittableList[0] = new Parallelepiped(Vec3(-0.25, -0.25, -1.0), Vec3(0.25, 0.25, -1.5), new Lambertian(Vec3(0.0, 0.2, 0.3)));
    list[0] = new Parallelepiped(Vec3(0.5, 0.5, -1.0), Vec3(1.0, 0.0, -1.0), Vec3(0.0, 1.0, 0.0), Vec3(-1.0, 0.0, -1.0), new Lambertian(Vec3(0.7, 0.2, 0.3)));
    list[1] = new Sphere(Vec3(0.0, -100.5, 0.0), 100.0, new Lambertian(Vec3(0.1, 0.3, 0.7)));
    list[2] = new Sphere(Vec3(0.0, 0.0, -1.0), 0.5, new Lambertian(Vec3(0.2, 0.7, 0.3)));
    // hittableList[0] = new Triangle(Vec3(-0.5, 0.5, -2.0), Vec3(0.5, 0.5, -2.0), Vec3(0.0, -0.5, -2.0), new Lambertian(Vec3(0.7, 0.2, 0.3)));
    // hittableList[0] = new Triangle(Vec3(-0.5, 0.5, -2.0), Vec3(-0.5, 0.0, -2.0), Vec3(0.0, 0.0, -1.0), new Lambertian(Vec3(0.3, 0.2, 0.7)));

    
    Hittable const * const world(new HittableList(list, count));

    Vec3 lookFrom(0.0, 0.0, 0.0);
    Vec3 lookAt(0.0, 0.0, -1.0);
    Vec3 up(0.0, 1.0, 0.0);
    float distanceToFocus((lookAt - lookFrom).length());
    float aperture(0.0);
    Camera const camera(lookFrom, lookAt, up, M_PI_2, float(nx) / float(ny), aperture, distanceToFocus);

    RayTracer rayTracer(std::move(filePath), Vec3(-1.0, 3.0, -2.0), 1.0, std::move(camera), std::move(world), 50);
    rayTracer.start(nx, ny, ns);

    return 0;
}
