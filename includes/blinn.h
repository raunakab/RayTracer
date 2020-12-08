#ifndef BLINN_H
#define BLINN_H

#include <blackbody.h>
#include <light.h>
#include <vec3.h>

class Blinn : public BlackBody {
private:
    Blinn() = delete;
    Blinn(Blinn const &) = delete;
    Blinn(Blinn const &&) = delete;

    void operator=(Blinn const &) = delete;
    void operator=(Blinn const &&) = delete;

public:
    float const shininess;
    float const kAmbient;
    float const kDiffuse;
    float const kSpecular;

    Blinn(Vec3 const &, float const, float const, float const, float const);
    ~Blinn();

    virtual bool scatter(Ray const &, HitRecord const &, Vec3 &, Ray &, Light const * const) const;
};

#endif
