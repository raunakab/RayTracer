#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include "./vec3/vec3.h"
#include "./vec3/vec3_utils.cpp"

std::string path("./out/");

int main() {
    std::ofstream fs;
    fs.open(path + "test.ppm");

    int const nx(200);
    int const ny(100);

    fs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
        int ir(255.99 * col[0]);
        int ig(255.99 * col[1]);
        int ib(255.99 * col[2]);

        fs << ir << " " << ig << " " << ib << "\n";
    }

    fs.close();
    return 0;
}
