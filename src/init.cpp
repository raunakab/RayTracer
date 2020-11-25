#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifndef INIT_CPP
#define INIT_CPP

struct Init {
    std::string filename;
    int nx;
    int ny;
    int error_code;

    Init(Init const &) = delete;
    void operator=(Init const &) = delete;
    void operator=(Init const &&) = delete;

    Init() : filename(""), nx(0), ny(0), error_code(0) {}
    Init(Init const && other) : filename(other.filename), nx(other.nx), ny(other.ny) {}
    ~Init() {}
    // Init(std::string const & filename, int const nx, int const ny) : filename(filename), nx(nx), ny(ny), error_code(0) {}
};

#endif
