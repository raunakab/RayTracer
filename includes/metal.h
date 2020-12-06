#ifndef METAL_H
#define METAL_H

#include <ray.h>
#include <vec3.h>
#include <vec3Utils.h>
#include <blackbody.h>

class Metal : public BlackBody {
private:
    Metal() = delete;
    Metal(Metal const &) = delete;
    Metal(Metal const &&) = delete;
    void operator=(Metal const &) = delete;
    void operator=(Metal const &&) = delete;

    float determineFuzz(float const fuzz) const;

public:
    float const fuzz;

    Metal(Vec3 const &, float const);
    ~Metal();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &) const;
};

#endif
