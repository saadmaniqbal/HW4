#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

namespace Raytracer148 {
class Sphere : public Shape {
public:
    Sphere(Eigen::Vector3d &center, double radius, Eigen::Vector3d &color, double reflect) : c(center), r(radius), col(color), ref(reflect) {}

    virtual HitRecord intersect(const Ray &ray);

private:
    Eigen::Vector3d c, col;
    double r, ref;
};
}

#endif
