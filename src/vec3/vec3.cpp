#include "./vec3.h"

vec3::vec3(float e1, float e2, float e3) : e({e1,e2,e3}) {}
vec3::~vec3() {}

inline float vec3::x() const { return this->e[0]; }
inline float vec3::y() const { return this->e[1]; }
inline float vec3::z() const { return this->e[2]; }

inline vec3 const & vec3::operator+() const { return *this; }
inline vec3 vec3::operator-() const { return vec3(-(this->e[0]), -(this->e[1]), -(this->e[2])); }
inline float vec3::operator[](int const i) const { return this->e[i]; }
inline float & vec3::operator[](int const i) { return this->e[i]; }

inline vec3 & vec3::operator+=(vec3 const & other) {
    this->e[0] += other.x();
    this->e[1] += other.y();
    this->e[2] += other.z();

    return *this;
}
inline vec3 & vec3::operator-=(vec3 const & other) {
    this->e[0] -= other.x();
    this->e[1] -= other.y();
    this->e[2] -= other.z();

    return *this;
}
inline vec3 & vec3::operator*=(vec3 const & other) {
    this->e[0] *= other.x();
    this->e[1] *= other.y();
    this->e[2] *= other.z();

    return *this;
}
inline vec3 & vec3::operator/=(vec3 const & other) {
    this->e[0] /= other.x();
    this->e[1] /= other.y();
    this->e[2] /= other.z();

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
    float const sd(this->squared_length());
    return sqrt(sd);
}

inline float vec3::squared_length() const {
    return (this->e[0])*(this->e[0]) + (this->e[1])*(this->e[1]) + (this->e[2])*(this->e[2]);
}
inline void vec3::make_unit_vector() {
    float const length(this->length());
    this->operator*=(length);

    return;
}
