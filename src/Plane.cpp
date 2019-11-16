#include "Plane.h"
#include <iostream>
#include <limits>
using namespace Raytracer148;
using namespace Eigen;
using namespace std;

HitRecord Plane::intersect(const Ray &ray) {
	//ray plane intersection is done based on the normal provided during the input and the center that goes through the plane
	//these two points are used to calculate the solution bt, and that is used to create the result parameters and returned
	HitRecord result;
	result.t = -1;
	result.color = col;
	result.reflectivity = ref;


	float denom = n.dot(ray.direction);
	if (abs(denom) > 0.0001) {
		double bt = n.dot(c - ray.origin) / denom;

		if (bt > 0.0001) {
			result.t = bt;
		}
	}
	
	result.position = ray.origin + result.t * ray.direction;
	result.normal = (result.position).normalized();

	return result;
}
	