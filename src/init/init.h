#include <stdio.h>
#include <stdlib.h>
#include <string>

#ifndef INIT_H
#define INIT_H

struct Init {
    std::string filename;
    int nx;
    int ny;
    int error_code;

    Init(Init const &) = delete;
    void operator=(Init const &) = delete;
    void operator=(Init const &&) = delete;

    Init();
    Init(Init const && other);
    ~Init();
};

#endif
