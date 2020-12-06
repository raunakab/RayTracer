#ifndef BLACKBODY_H
#define BLACKBODY_H

#include <material.h>
#include <vec3.h>

class BlackBody : public Material {
private:
    BlackBody() = delete;
    BlackBody(BlackBody const &) = delete;
    BlackBody(BlackBody const &&) = delete;
    void operator=(BlackBody const &) = delete;
    void operator=(BlackBody const &&) = delete;

public:
    Vec3 const albedo;

    BlackBody(Vec3 const & albedo);
    virtual ~BlackBody();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &) const = 0;
};

#endif
