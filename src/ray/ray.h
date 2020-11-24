#ifndef RAY_H
#define RAY_H

#include "../vec3/vec3.h"

class ray {
private:
    ray() = delete;
    void operator=(ray const &) = delete;
    void operator=(ray const &&) = delete;

public:
    vec3 const A;
    vec3 const B;

    ray(vec3 const origin, vec3 const direction);
    ray(ray const &);
    ray(ray const &&);
    ~ray();

    vec3 origin() const;
    vec3 direction() const;
    vec3 point_at_parameter(float const t) const;
};

#endif
