# HW4
HW4 for COSC 4370 Prof. Deng

This HW was compiled and run on Visual Studio 2017 with the updated Eigen Package. All four parts of the HW were addressed.

For Part 1, I created a plane and a triangle as per the requirements of the question, plane being a primitive and the formulae for the functions and its interpretation were inspired from articles on the internet and related githubs, such as:

https://www.cl.cam.ac.uk/teaching/1999/AGraphHCI/SMAG/node2.html

and

https://github.com/chiangqiqi

relavant .cpp and .h files were created in the process as well.

For Part 2, Phong Shading and adding color was done based on the last HW, this included ambient, diffuse and specular lighting. Adding specific color to different objects were done by changing the constructors during the creation of the new shapes and then passing it while tracing from hitrecords. 

For Part 3, ideas for the formulae and logic behind casting shadows were similarly inspired from places like 

https://www.scratchapixel.com/

The procedure followed are mentioned in the comments in my code. Due to limitations on the starter code, I couldn't manage to remove some shadow acne and thus a slight bit of it remains present. The shadows are casted correctly on the plane created behind the spheres and the slanted triangle.

For Part 4, due to my inability to follow the recursive approach inside the trace function to build the reflectivity on different object surfaces, I had drawn inspiration again from the internet to find a way to implement a reflective surface from the rendering function by creating a frosted mirror like surface by changing color of the pixels below a certain point and overlap that with inverted images of my objects. That has been implemented correctly.





Testing Testing