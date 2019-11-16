#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

namespace Raytracer148 {
	class Plane : public Shape {
	public:
		Plane(Eigen::Vector3d &center, Eigen::Vector3d &normal, Eigen::Vector3d &color, double reflect) : c(center), n(normal), col(color), ref(reflect) {}

		virtual HitRecord intersect(const Ray &ray);

	private:
		Eigen::Vector3d c, n, col;
		double ref;

	};
}

#endif

