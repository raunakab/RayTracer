#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

std::string path("./out/");

int main() {
    std::ofstream fs;
    fs.open(path + "test.ppm");

    int const nx(200);
    int const ny(100);

    fs << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j(ny-1); j>=0; --j) for (int i(0); i<nx; ++i) {
        float r(float(i) / float(nx));
        float g(float(j) / float(ny));
        float b(0.2);
        int ir(255.99 * r);
        int ig(255.99 * g);
        int ib(255.99 * b);

        fs << ir << " " << ig << " " << ib << "\n";
    }

    fs.close();
    return 0;
}
