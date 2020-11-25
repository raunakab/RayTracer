#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>

#include "vec3/vec3.h"
#include "vec3/vec3_utils.cpp"
#include "ray/ray.h"

std::string const path("./out/");
std::ofstream fs;

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

//     return (discriminant > 0);
// }

Vec3 colour(Ray const & r) {
    Vec3 const center(0.0, 0.0, 1.0);

    float const t_0(hit_sphere(center, 0.5, r));
    if (t_0 > 0.0) {
        Vec3 const N(unit_vector(r.point_at_parameter(t_0) - center));
        return 0.5 * Vec3(N.x()+1, N.y()+1, N.z()+1);
    }

    Vec3 const u(unit_vector(r.direction()));
    float const t(0.5 * (u.y() + 1.0));
    return ((1.0 - t) * Vec3(1.0, 1.0, 1.0)) + (t * Vec3(0.5, 0.7, 1.0));
}

int main(int argc, char ** argv) {
    if (argc != 4) {
        std::cout << "incorrect number of arguments\n";
        return -1;
    }

    std::string const filename(argv[1]);
    int nx(0);
    int ny(0);

    try {
        nx = std::stoi(std::string(argv[2]));
    } catch (...) {
        std::cout << "invalid 2nd operand\n";
        return -1;
    }
    try {
        ny = std::stoi(std::string(argv[3]));
    } catch (...) {
        std::cout << "invalid 3rd operand\n";
        return -1;
    }

    fs.open(path + filename + ".ppm");

    Vec3 const lower_left_corner(-2.0, -1.0, -1.0);
    Vec3 const horizontal(4.0, 0.0, 0.0);
    Vec3 const vertical(0.0, 2.0, 0.0);
    Vec3 const origin(0.0, 0.0, 0.0);

    fs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        float u(float(i) / float(nx));
        float v(float(j) / float(ny));

        // vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
        Ray const r(origin, lower_left_corner + (u * horizontal) + (v * vertical));
        Vec3 col(colour(r));

        int ir(255.99 * col[0]);
        int ig(255.99 * col[1]);
        int ib(255.99 * col[2]);

        fs << ir << " " << ig << " " << ib << "\n";
    }

    fs.close();
    return 0;
}
