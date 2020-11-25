#include "vec3.h"

Vec3::Vec3(float const e0, float const e1, float const e2) {
    // initializer list does not work for clang++
    this->e[0] = e0;
    this->e[1] = e1;
    this->e[2] = e2;

    return;
}
Vec3::Vec3(Vec3 const & other) {
    // initializer list does not work for clang++
    this->e[0] = other.e[0];
    this->e[1] = other.e[1];
    this->e[2] = other.e[2];

    return;
}
Vec3::Vec3(Vec3 const && other) {
    // initializer list does not work for clang++
    this->e[0] = other.e[0];
    this->e[1] = other.e[1];
    this->e[2] = other.e[2];

    return;
}
Vec3::~Vec3() { return; }

void Vec3::operator=(Vec3 const & other) {
    this->e[0] = other.e[0];
    this->e[1] = other.e[1];
    this->e[2] = other.e[2];

    return;
}
void Vec3::operator=(Vec3 const && other) {
    this->e[0] = other.e[0];
    this->e[1] = other.e[1];
    this->e[2] = other.e[2];

    return;
}
