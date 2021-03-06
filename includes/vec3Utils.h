#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vec3.h>

#ifndef VEC3UTILS_H
#define VEC3UTILS_H

inline std::istream & operator>>(std::istream & is, Vec3 & v) {
    is >> v.e[0] >> v.e[1] >> v.e[2];
    return is;
}
inline std::ostream & operator<<(std::ostream & os, Vec3 & v) {
    os << v.e[0] << " " << v.e[1] << " " << v.e[2];
    return os;
}

inline Vec3 operator+(Vec3 const & v1, Vec3 const & v2) {
    return Vec3(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}
inline Vec3 operator-(Vec3 const & v1, Vec3 const & v2) {
    return Vec3(v1.e[0]-v2.e[0], v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]);
}
inline Vec3 operator*(Vec3 const & v1, Vec3 const & v2) {
    return Vec3(v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]*v2.e[2]);
}
inline Vec3 operator/(Vec3 const & v1, Vec3 const & v2) {
    return Vec3(v1.e[0]/v2.e[0], v1.e[1]/v2.e[1], v1.e[2]/v2.e[2]);
}

inline Vec3 operator*(Vec3 const & v, float const t) {
    return Vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}
inline Vec3 operator/(Vec3 const & v, float const t) {
    return Vec3(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline Vec3 operator*(float const t, Vec3 const & v) {
    return Vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}
inline float dot(Vec3 const & v1, Vec3 const & v2) {
    return (v1.e[0]*v2.e[0]) + (v1.e[1]*v2.e[1]) + (v1.e[2]*v2.e[2]);
}
inline Vec3 cross(Vec3 const & v1, Vec3 const & v2) {
    return Vec3((v1.e[1]*v2.e[2])-(v1.e[2]*v2.e[1]), -((v1.e[0]*v2.e[2])-(v1.e[2]*v2.e[0])), (v1.e[0]*v2.e[1])-(v1.e[1]*v2.e[0]));
}

inline Vec3 unitVector(Vec3 const & v) {
    return v / (v.length());
}

Vec3 randomUnitVector();
Vec3 randomInUnitDisk();
void reflect(Vec3 const &, Vec3 const &, Vec3 &);
bool refract(Vec3 const &, Vec3 const &, float const, Vec3 &);
float schlick(float const, float const);
bool withinRange(float const, float const, float const);

// my own additions
inline std::ofstream & operator<<(std::ofstream & ofs, Vec3 & v) {
    ofs << int(v.e[0]) << " " << int(v.e[1]) << " " << int(v.e[2]) << "\n";

    return ofs;
}

#endif
