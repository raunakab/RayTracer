#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifndef VEC3_H
#define VEC3_H

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

inline float vec3::x() const { return this->e[0]; }
inline float vec3::y() const { return this->e[1]; }
inline float vec3::z() const { return this->e[2]; }

inline vec3 const & vec3::operator+() const { return *this; }
inline vec3 vec3::operator-() const { return vec3(-(this->e[0]), -(this->e[1]), -(this->e[2])); }
inline float vec3::operator[](int const i) const { return this->e[i]; }
inline float & vec3::operator[](int const i) { return this->e[i]; }

inline vec3 & vec3::operator+=(vec3 const & other) {
    this->e[0] += other.e[0];
    this->e[1] += other.e[1];
    this->e[2] += other.e[2];

    return *this;
}
inline vec3 & vec3::operator-=(vec3 const & other) {
    this->e[0] -= other.e[0];
    this->e[1] -= other.e[1];
    this->e[2] -= other.e[2];

    return *this;
}
inline vec3 & vec3::operator*=(vec3 const & other) {
    this->e[0] *= other.e[0];
    this->e[1] *= other.e[1];
    this->e[2] *= other.e[2];

    return *this;
}
inline vec3 & vec3::operator/=(vec3 const & other) {
    this->e[0] /= other.e[0];
    this->e[1] /= other.e[1];
    this->e[2] /= other.e[2];

    return *this;
}

inline vec3 & vec3::operator*=(float const t) {
    this->e[0] *= t;
    this->e[1] *= t;
    this->e[2] *= t;

    return *this;
}
inline vec3 & vec3::operator/=(float const t) {
    this->e[0] /= t;
    this->e[1] /= t;
    this->e[2] /= t;

    return *this;
}

inline float vec3::length() const {
    float const sd(this->squared_length()); // convert this into a non-function call?
    return sqrt(sd);
}
inline float vec3::squared_length() const {
    return (this->e[0])*(this->e[0]) + (this->e[1])*(this->e[1]) + (this->e[2])*(this->e[2]);
}
inline void vec3::make_unit_vector() {
    float const length(this->length());
    (*this) *= length;

    return;
}

#endif
