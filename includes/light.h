#ifndef LIGHT_H
#define LIGHT_H

#include <vec3.h>
#include <hittable.h>

class Light {
private:
    Light() = delete;
    Light(Light const &) = delete;
    Light(Light const &&) = delete;
    void operator=(Light const &) = delete;
    void operator=(Light const &&) = delete;

public:
    Vec3 const lightPosition;
    float const lightContribution;
    float const shadowContribution;
    float const lightFuzz;

    Light(Vec3 const &, float const, float const, float const);
    virtual ~Light();

    virtual float contribution(Hittable const * const, Vec3 const &) const = 0;
};

#endif
