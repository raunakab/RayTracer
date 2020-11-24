#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "vec3/vec3.h"
#include "vec3/vec3_utils.cpp"
#include "ray/ray.h"

std::string const path("./out/");
std::ofstream fs;

vec3 colour(ray const & r) {
    vec3 u(unit_vector(r.direction()));
    float t(0.5 * (u.y() + 1.0));
    return ((1.0 - t) * vec3(1.0, 1.0, 1.0)) + (t * vec3(0.5, 0.7, 1.0));
}

int main() {
    fs.open(path + "image.ppm");

    int const nx(200);
    int const ny(100);

    vec3 const lower_left_corner(-2.0, -1.0, -1.0);
    vec3 const horizontal(4.0, 0.0, 0.0);
    vec3 const vertical(0.0, 2.0, 0.0);
    vec3 const origin(0.0, 0.0, 0.0);

    fs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        float u(float(i) / float(nx));
        float v(float(j) / float(ny));

        // vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
        ray const r(origin, (u * horizontal) + (v * vertical));
        vec3 col(colour(r));

        int ir(255.99 * col[0]);
        int ig(255.99 * col[1]);
        int ib(255.99 * col[2]);

        fs << ir << " " << ig << " " << ib << "\n";
    }

    fs.close();
    return 0;
}
