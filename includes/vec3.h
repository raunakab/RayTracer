#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#ifndef VEC3_H
#define VEC3_H

class Vec3 {
private:
    Vec3() = delete;

public:
    float e[3];

    Vec3(float const e1, float const e2, float const e3);
    Vec3(Vec3 const &);
    Vec3(Vec3 const &&);
    ~Vec3();

    void operator=(Vec3 const &);
    void operator=(Vec3 const &&);

    inline float x() const;
    inline float y() const;
    inline float z() const;

    inline float r() const;
    inline float g() const;
    inline float b() const;

    inline Vec3 const & operator+() const;
    inline Vec3 operator-() const;
    inline float operator[](int const i) const;
    inline float & operator[](int const i);

    inline Vec3 & operator+=(Vec3 const & other);
    inline Vec3 & operator-=(Vec3 const & other);
    inline Vec3 & operator*=(Vec3 const & other);
    inline Vec3 & operator/=(Vec3 const & other);

    inline Vec3 & operator*=(float const t);
    inline Vec3 & operator/=(float const t);

    inline float length() const;
    inline float squaredLength() const;
    inline void makeUnitVector();
};

inline float Vec3::x() const { return this->e[0]; }
inline float Vec3::y() const { return this->e[1]; }
inline float Vec3::z() const { return this->e[2]; }

inline Vec3 const & Vec3::operator+() const { return *this; }
inline Vec3 Vec3::operator-() const { return Vec3(-(this->e[0]), -(this->e[1]), -(this->e[2])); }
inline float Vec3::operator[](int const i) const { return this->e[i]; }
inline float & Vec3::operator[](int const i) { return this->e[i]; }

inline Vec3 & Vec3::operator+=(Vec3 const & other) {
    this->e[0] += other.e[0];
    this->e[1] += other.e[1];
    this->e[2] += other.e[2];

    return *this;
}
inline Vec3 & Vec3::operator-=(Vec3 const & other) {
    this->e[0] -= other.e[0];
    this->e[1] -= other.e[1];
    this->e[2] -= other.e[2];

    return *this;
}
inline Vec3 & Vec3::operator*=(Vec3 const & other) {
    this->e[0] *= other.e[0];
    this->e[1] *= other.e[1];
    this->e[2] *= other.e[2];

    return *this;
}
inline Vec3 & Vec3::operator/=(Vec3 const & other) {
    this->e[0] /= other.e[0];
    this->e[1] /= other.e[1];
    this->e[2] /= other.e[2];

    return *this;
}

inline Vec3 & Vec3::operator*=(float const t) {
    this->e[0] *= t;
    this->e[1] *= t;
    this->e[2] *= t;

    return *this;
}
inline Vec3 & Vec3::operator/=(float const t) {
    this->e[0] /= t;
    this->e[1] /= t;
    this->e[2] /= t;

    return *this;
}

inline float Vec3::length() const {
    float const sd(this->squaredLength()); // convert this into a non-function call?
    return sqrt(sd);
}
inline float Vec3::squaredLength() const {
    return (this->e[0])*(this->e[0]) + (this->e[1])*(this->e[1]) + (this->e[2])*(this->e[2]);
}
inline void Vec3::makeUnitVector() {
    float const length(this->length());
    (*this) *= length;

    return;
}

#endif
