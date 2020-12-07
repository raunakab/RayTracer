#ifndef BLINN_H
#define BLINN_H

#include <material.h>

class Blinn : public Material {
private:
    Blinn(Blinn const &) = delete;
    Blinn(Blinn const &&) = delete;

    void operator=(Blinn const &) = delete;
    void operator=(Blinn const &&) = delete;

public:
    Blinn();
    ~Blinn();
};

#endif
