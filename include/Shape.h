#ifndef SHAPE_H
#define SHAPE_H

#include <Eigen/Dense>

namespace Raytracer148 {
struct Ray {
  Eigen::Vector3d origin, direction;
};

class Shape;

struct HitRecord {
  Eigen::Vector3d position, normal, color;
  double t, reflectivity;
};

class Shape {
public:
  virtual ~Shape(){}
  virtual HitRecord intersect(const Ray &ray) = 0;
};

}

#endif
