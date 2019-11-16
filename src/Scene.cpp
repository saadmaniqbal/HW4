#include "Scene.h"
#include <cmath>
using namespace Raytracer148;
using namespace std;
using namespace Eigen;

HitRecord Scene::closestHit(const Ray &ray) {
    HitRecord result;
    result.t = -1;
    bool foundSomething = false;

    for (unsigned int i = 0; i < shapes.size(); i++) {
        HitRecord r = shapes[i]->intersect(ray);
        if (r.t > std::numeric_limits<double>::epsilon() && (!foundSomething || r.t < result.t)) {
            result = r;
            foundSomething = true;
        }
    }

    return result;
}

// Returns an RGB color, where R/G/B are each in the range [0,1]
Vector3d Scene::trace(const Ray &ray) {
    // For now we'll have diffuse shading with no shadows, so it's easy!

	//the idea for the shadows is - ray being reflected from the eye ray after intersecting with the object will travel back to the light point
	//if it hits any other objects, then a shadow will be casted

	//reflect rays are declared and intersection of that ray with all the other objects on the scene are checked in the loop.

	//afterwards, ambient and specular lighting is added based on our work from hw3


    HitRecord r = closestHit(ray);
    Vector3d result;

    if (r.t < numeric_limits<double>::epsilon()) return result;

    Vector3d lightDir = (lightPos - r.position).normalized();

	Ray reflect;
	reflect.origin = r.position;
	reflect.direction = lightDir;

	

	for (unsigned int i = 0; i < shapes.size(); i++) {
		HitRecord r = shapes[i]->intersect(reflect);
		if (r.t > 0.00000001)  return result;

	}

    double dot = lightDir.dot(r.normal);
    if (dot < 0) dot = 0;

	Vector3d diffuse = dot * r.color;

	double ambientStrength = 0.1f;
	Vector3d ambient = ambientStrength * r.color;

	double specularStrength = 0.2f;
	//Vector3d viewDir = (lightPos - r.position).normalized();
	Vector3d cameraDirection = (-r.position).normalized();
	Vector3d half_direction = (lightDir + cameraDirection).normalized();
	double dot2 = half_direction.dot(r.normal);
	
	if (dot2 < 0) dot2 = 0;

	double spec = pow(dot2, 16.0);
	Vector3d specular = specularStrength * spec * r.color;

	result = ambient + diffuse + specular;

	for (int i = 0; i < 3; i++) {
		if (result[i] > 1.0)
			result[i] = 1.0;
	}
	
	//Vector 

    //result[0] = result[1] = result[2] = dot;
    return result;
}

void Scene::render(Image &image) {
    // We make the assumption that the camera is located at (0,0,0)
    // and that the image plane happens in the square from (-1,-1,1)
    // to (1,1,1).

	assert(image.getWidth() == image.getHeight());


	//the reflection and mirroring is done here while rendering. I was unable to implement the regular way of making reflective surfaces
	//in tracing using the starter  code, so the implementation below is a makeshift of a linear reflection from on a surface created by
	//the individual pixels, create a frosted surface and imprint the objects created in a reflective manner.


	int size = image.getWidth();
	double pixelSize = 2. / size;
	for (int x = 0; x < size; x++)

		for (int y = 0; y < size; y++) {

			Ray curRay;
			float mirror_placement = size - y;
			float pos = y + 150;
			float frosting_factor = 0.3;
			Vector3d color;

			curRay.origin[0] = curRay.origin[1] = curRay.origin[2] = 0;


			curRay.direction[0] = (x + 0.5)*pixelSize - 1;
			curRay.direction[1] = 1 - (y + 0.5)*pixelSize;
			curRay.direction[2] = 1;


			double r, g, b = 0;
			pixel_t *pix = image.pixelAt(x, y);

			r = (double)pix->red;
			g = (double)pix->green;
			b = (double)pix->blue;

			if (r == 0 && g == 0 && b == 0) {
				color = trace(curRay);
				image.setColor(x, y, color[0], color[1], color[2]);
			}

			if (mirror_placement < size && mirror_placement >pos) {
				image.setColor(x, mirror_placement, color[0] + frosting_factor, color[1] + frosting_factor, color[2] + frosting_factor);
			}
			

		}
}
