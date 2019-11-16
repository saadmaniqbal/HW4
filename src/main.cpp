#include <iostream>
#include "Image.h"
#include "Scene.h"
#include "Sphere.h"
#include "Plane.h"
#include "triangle.h"
using namespace std;
using namespace Raytracer148;
using namespace Eigen;

int main() {
    Image im(400, 400);

    Scene scene;
	//different colors and centers/vertices/radii/normals are added for each of the objects. This was basically done by trial and error
	//reflectivity was initially added but never used due to time constraints and failure to implement it. 
	Vector3d color;
	color[0] = 0.4;
	color[1] = 0.8;
	color[2] = 0.5;


    Vector3d center, normal;
	center[0] = -0.7;
    center[1] = 0.5;
    center[2] = 2.0;
    scene.addShape(new Sphere(center, 0.5, color, 2.0));

	color[0] = 0.5;
	color[1] = 0.7;
	color[2] = 0.7;

    center[0] = -0.3;
    center[1] = 1.0;
    center[2] = 3.0;
    scene.addShape(new Sphere(center, 0.5, color, 0.0));

	color[0] = 0.7;
	color[1] = 0.6;
	color[2] = 0.5;


	center[0] = 0;
	center[1] = -0.75;
	center[2] = 5;

	normal[0] = 1;
	normal[1] = 0;
	normal[2] = 5;

	

	scene.addShape(new Plane(center, normal, color,0.0));


	Vector3d Vertex1, Vertex2, Vertex3;


	color[0] = 0.5;
	color[1] = 0;
	color[2] = 0;


	Vertex1[0] = 3.5;
	Vertex1[1] = -0.5;
	Vertex1[2] = 3.5-0.4;

	Vertex2[0] = 0.75;
	Vertex2[1] = 1;
	Vertex2[2] = 2-0.4;

	Vertex3[0] = 0;
	Vertex3[1] = -0.75;
	Vertex3[2] = 5-0.4;
		
	

	scene.addShape(new triangle(Vertex1, Vertex2, Vertex3, color));



    scene.render(im);

    im.writePNG("test.png");

    return 0;
}
