
#include "Triangle.h"
#include <iostream>

// Default Constructor
Triangle::Triangle() {
}

// Constructor
Triangle::Triangle(vec3 first, vec3 second, vec3 third, vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess) 
	              : Shape(ambientColor, diffusedColor, specularColor, shininess) {
	this->vertexOne = first;
	this->vertexTwo = second;
	this->vertexThree = third;

	std::cout << "created triangle: " << vertexOne.x << ", " << vertexOne.y << ", " << vertexOne.z << std::endl;
}

// Destructor
Triangle::~Triangle() {
}

// Getter: Return First Vertex
vec3 Triangle::getVertexOne() {
	return vertexOne;
}

// Getter: Return Second Vertex
vec3 Triangle::getVertexTwo() {
	return vertexTwo;
}

// Getter: Return Third Vertex
vec3 Triangle::getVertexThree() {
	return vertexThree;
}

// Triangle Intersection (Based off Tutorials on ScratchPixel.com)
bool Triangle::intersection(Ray rayCast, float &intersection) {

	vec3 p1p2 = this->vertexTwo - this->vertexOne;
	vec3 p1p3 = this->vertexThree - this->vertexOne;

	vec3 cp = cross(p1p2, p1p3);
	float area = cp.length();

	// Check for Parallelism
	float rayDir = dot(cp, rayCast.getDirection());
	if (fabs(rayDir) < 0) {
		return false;
	}

	float d = dot(cp, vertexOne);

	intersection = (d + dot(cp, rayCast.getOrigin())) / rayDir;

	if (intersection < 0)
		return false;

	vec3 p = rayCast.getOrigin() + intersection * rayCast.getDirection();

	vec3 c;

	vec3 edge1 = p1p2;
	vec3 vp1 = p - vertexOne;
	c = cross(edge1, vp1);
	if (dot(cp, c) < 0)
		return false;
	
	vec3 edge2 = vertexThree - vertexTwo;
	vec3 vp2 = p - vertexTwo;
	c = cross(edge2, vp2);
	if (dot(cp, c) < 0)
		return false;

	vec3 edge3 = vertexOne - vertexThree;
	vec3 vp3 = p - vertexThree;
	c = cross(edge3, vp3);
	if (dot(cp, c) < 0)
		return false;

	return true;

}
