#ifndef HITTABLELIST_H
#define HITTABLELIST_H

#include <hittable.h>
#include <ray.h>

class HittableList : public Hittable {
private:
    HittableList() = delete;
    HittableList(HittableList const &) = delete;
    HittableList(HittableList const &&) = delete;

    void operator=(HittableList const &) = delete;
    void operator=(HittableList const &&) = delete;

public:
    Hittable ** list;
    int const length;

    HittableList(Hittable ** const, int const);
    ~HittableList();

    virtual bool hit(Ray const &, float const, float const, HitRecord &) const;
};

#endif