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

    Light(Vec3 const &);
    virtual ~Light();

    virtual float contribution(Hittable const * const, Vec3 const &) const = 0;
};

#endif
