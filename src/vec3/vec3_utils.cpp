#include "./vec3.h"

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

// my own additions
inline std::ofstream & operator<<(std::ofstream & ofs, vec3 & v) {
    ofs << v.e[0] << " " << v.e[1] << " " << v.e[2];

    return ofs;
}
