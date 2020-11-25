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

bool hit_sphere(vec3 const & center, float const radius, ray const & r) {
    vec3 const Q(r.origin() - center);
    vec3 const P(r.direction());
    float const J(dot(P, Q));
    float const determinant(J*J - dot(Q, Q)*(dot(P, P) - (radius*radius)));

    return (determinant > 0);
}

// bool hit_sphere(vec3 const & center, float const radius, ray const & r) {
//     vec3 const oc(r.origin() - center);
//     float a(dot(r.direction(), r.direction()));
//     float b(2.0 * dot(oc, r.direction()));
//     float c(dot(oc, oc) - radius*radius);
//     float discriminant(b*b - 4.0*a*c);

//     return (discriminant > 0);
// }

vec3 colour(ray const & r) {
    if (hit_sphere(vec3(0.0, 0.0, -1000.0), 0.5, r)) return vec3(1.0, 0.0, 0.0);

    vec3 u(unit_vector(r.direction()));
    float t(0.5 * (u.y() + 1.0));
    return ((1.0 - t) * vec3(1.0, 1.0, 1.0)) + (t * vec3(0.5, 0.7, 1.0));
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

    // int const nx(2000);
    // int const ny(1000);

    vec3 const lower_left_corner(-2.0, -1.0, -1.0);
    vec3 const horizontal(4.0, 0.0, 0.0);
    vec3 const vertical(0.0, 2.0, 0.0);
    vec3 const origin(0.0, 0.0, 0.0);

    fs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        float u(float(i) / float(nx));
        float v(float(j) / float(ny));

        // vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
        ray const r(origin, lower_left_corner + (u * horizontal) + (v * vertical));
        vec3 col(colour(r));

        int ir(255.99 * col[0]);
        int ig(255.99 * col[1]);
        int ib(255.99 * col[2]);

        fs << ir << " " << ig << " " << ib << "\n";
    }

    fs.close();
    return 0;
}
