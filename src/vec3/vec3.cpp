#include "vec3.h"

vec3::vec3(float const e0, float const e1, float const e2) {
    // initializer list does not work for clang++
    this->e[0] = e0;
    this->e[1] = e1;
    this->e[2] = e2;

    return;
}
vec3::vec3(vec3 const & other) {
    // initializer list does not work for clang++
    this->e[0] = other.e[0];
    this->e[1] = other.e[1];
    this->e[2] = other.e[2];

    return;
}
vec3::vec3(vec3 const && other) {
    // initializer list does not work for clang++
    this->e[0] = other.e[0];
    this->e[1] = other.e[1];
    this->e[2] = other.e[2];

    return;
}
vec3::~vec3() { return; }
