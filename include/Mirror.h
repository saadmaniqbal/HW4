#ifndef MIRROR_H
#define MIRROR_H

#include "Shape.h"

namespace Raytracer148 {
	class Mirror : public Shape {
	public:
		Mirror(Eigen::Vector3d &center, double radius, Eigen::Vector3d &color, double reflect) : c(center), r(radius), col(color), ref(reflect) {}

		virtual HitRecord intersect(const Ray &ray);

	private:
		Eigen::Vector3d c, col;
		double r, ref;
	};
}

#endif
