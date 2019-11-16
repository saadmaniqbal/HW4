
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"



namespace Raytracer148 {
	//similar to the sphere, this is also defined using vertices and the color for the triangle, as well as records for the ray hits.
	class  triangle : public Shape {

	public:

		triangle(Eigen::Vector3d &p1, Eigen::Vector3d &p2, Eigen::Vector3d &p3, Eigen::Vector3d &color) : v1(p1), v2(p2), v3(p3), col(color){}
		virtual HitRecord intersect(const Ray &ray);

	private:

		Eigen::Vector3d v1,v2,v3,col;

	};

}



#endif