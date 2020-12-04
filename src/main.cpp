#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <float.h>
#include <Logger/logger.h>

#include <vec3.h>
#include <vec3_utils.h>
#include <ray.h>
#include <init.h>
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

// bool hit_sphere(vec3 const & center, float const radius, ray const & r) {
//     vec3 const oc(r.origin() - center);
//     float a(dot(r.direction(), r.direction()));
//     float b(2.0 * dot(oc, r.direction()));
//     float c(dot(oc, oc) - radius*radius);
//     float discriminant(b*b - 4.0*a*c);
//
//     return (discriminant > 0);
// }

Vec3 colour(Ray const & r, Hittable * const world) {
    HitRecord hr;

    if (world->hit(r, 0.0, MAXFLOAT, hr)) {
        // Vec3 & hr_normal(hr.normal);
        // ++(hr_normal.e[0]);
        // ++(hr_normal.e[1]);
        // ++(hr_normal.e[2]);

        // return 0.5 * hr_normal;
        return 0.5 * Vec3(hr.normal.x()+1.0, hr.normal.y()+1.0, hr.normal.z()+1.0);
    } else {
        Vec3 const u(unit_vector(r.direction()));
        float const t(0.5 * (u.y() + 1.0));

        return ((1.0 - t) * Vec3(1.0, 1.0, 1.0)) + (t * Vec3(0.5, 0.7, 1.0));
    }

    // float const t_0(hit_sphere(center, 0.5, r));
    // if (t_0 > 0.0) {
    //     Vec3 const N(unit_vector(r.point_at_parameter(t_0) - center));
    //     return 0.5 * Vec3(N.x()+1, N.y()+1, N.z()+1);
    // }

    // Vec3 const u(unit_vector(r.direction()));
    // float const t(0.5 * (u.y() + 1.0));
    // return ((1.0 - t) * Vec3(1.0, 1.0, 1.0)) + (t * Vec3(0.5, 0.7, 1.0));
}

void setup(int argc, char ** argv, std::ofstream & fs, int & nx, int & ny) {
    if (argc != 4) Logger::error(std::string("incorrect number of arguments"), -1);

    try {
        nx = std::stoi(std::string(argv[2]));
    } catch (...) {
        Logger::error(std::string("invalid 2nd operand"), -1);
    }
    try {
        ny = std::stoi(std::string(argv[3]));
    } catch (...) {
        Logger::error(std::string("invalid 3rd operand"), -1);
    }

    fs.open("./../../out/" + std::string(argv[1]) + ".ppm");
    fs << "P3\n" << nx << " " << ny << "\n255\n";

    return;
}

int main(int argc, char ** argv) {
    std::ofstream fs;
    int nx;
    int ny;

    setup(argc, argv, fs, nx, ny);

    Vec3 const lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 const horizontal(4.0, 0.0, 0.0);
    Vec3 const vertical(0.0, 2.0, 0.0);
    Vec3 const origin(0.0, 0.0, 0.0);

    Hittable * hl[2];
    hl[0] = new Sphere(Vec3(0.0, 0.0, -1.0), 0.5);
    hl[1] = new Sphere(Vec3(0.0, -100.5, -1.0), 100.0);

    Hittable * const world(new HittableList(hl, 2));

    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        float u(float(i) / float(nx));
        float v(float(j) / float(ny));
        Ray const r(origin, lower_left_corner + (u * horizontal) + (v * vertical));

        Vec3 col(colour(r, world));

        col *= 255.99;
        fs << col;
    }

    delete hl[0];
    delete hl[1];
    delete world;

    fs.close();
    return 0;
}
