#ifndef VEC3_H
#define VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

class vec3 {
private:
    vec3(vec3 const &) = delete;
    vec3(vec3 const &&) = delete;
    void operator=(vec3 const &) = delete;
    void operator=(vec3 const &&) = delete;

public:
    float e[3];

    vec3(float const e1, float const e2, float const e3);
    ~vec3();

    inline float x() const;
    inline float y() const;
    inline float z() const;

    inline float r() const;
    inline float g() const;
    inline float b() const;

    inline vec3 const & operator+() const;
    inline vec3 operator-() const;
    inline float operator[](int const i) const;
    inline float & operator[](int const i);

    inline vec3 & operator+=(vec3 const & other);
    inline vec3 & operator-=(vec3 const & other);
    inline vec3 & operator*=(vec3 const & other);
    inline vec3 & operator/=(vec3 const & other);

    inline vec3 & operator*=(float const t);
    inline vec3 & operator/=(float const t);

    inline float length() const;
    inline float squared_length() const;
    inline void make_unit_vector();
};

#endif
