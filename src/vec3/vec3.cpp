#include "./vec3.h"

vec3::vec3(float const e1, float const e2, float const e3) : e({e1,e2,e3}) {}
vec3::~vec3() {}

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

inline std::istream & operator>>(std::istream & is, vec3 & v) {
    is >> v.e[0] >> v.e[1] >> v.e[2];
    return is;
}
inline std::ostream & operator<<(std::ostream & os, vec3 & v) {
    os << v.e[0] << " " << v.e[1] << " " << v.e[2];
    return os;
}

inline vec3 operator+(vec3 const & v1, vec3 const & v2) {
    return vec3(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}
inline vec3 operator-(vec3 const & v1, vec3 const & v2) {
    return vec3(v1.e[0]-v2.e[0], v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]);
}
inline vec3 operator*(vec3 const & v1, vec3 const & v2) {
    return vec3(v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]*v2.e[2]);
}
inline vec3 operator/(vec3 const & v1, vec3 const & v2) {
    return vec3(v1.e[0]/v2.e[0], v1.e[1]/v2.e[1], v1.e[2]/v2.e[2]);
}

inline vec3 operator*(vec3 const & v, float const t) {
    return vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}
inline vec3 operator/(vec3 const & v, float const t) {
    return vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline vec3 operator*(float const t, vec3 const & v) {
    return vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}
inline float dot(vec3 const & v1, vec3 const & v2) {
    return (v1.e[0]*v2.e[0]) + (v1.e[1]*v2.e[1]) + (v1.e[2]*v2.e[2]);
}
inline vec3 cross(vec3 const & v1, vec3 const & v2) {
    return vec3((v1.e[1]*v2.e[2])-(v1.e[2]*v2.e[1]), -((v1.e[0]*v2.e[2])-(v1.e[2]*v2.e[0])), (v1.e[0]*v2.e[1])-(v1.e[1]*v2.e[0]));
}

inline vec3 unit_vector(vec3 const & v) {
    return v / (v.length());
}
