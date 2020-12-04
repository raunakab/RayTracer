#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include <material.h>
#include <vec3Utils.h>

class Dielectric : public Material {
private:
    Dielectric() = delete;
    Dielectric(Dielectric const &) = delete;
    Dielectric(Dielectric const &&) = delete;

    void operator=(Dielectric const &) = delete;
    void operator=(Dielectric const &&) = delete;

public:
    float const refractionIndex;

    Dielectric(float const);
    ~Dielectric();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &) const;
};

#endif
