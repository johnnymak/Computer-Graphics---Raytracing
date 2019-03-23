
#include "Sphere.h"
#include <iostream>

// Default Constructor
Sphere::Sphere() {
}

// Constructor
Sphere::Sphere(vec3 position, int radius, vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess) 
	          : Shape(ambientColor, diffusedColor, specularColor, shininess) {
	this->center = position;
	this->radius = radius;

	std::cout << "created sphere: " << center.x << ", " << center.y << ", " << center.z << std::endl;
}

// Destructor
Sphere::~Sphere() {
}

// Getter: Return Position of Center
vec3 Sphere::getCenter() {
	return center;
}

// Getter: Return Radius
int Sphere::getRadius() {
	return radius;
}

// Sphere Intersection (Based off Tutorials on ScratchPixel.com)
bool Sphere::intersection(Ray rayCast, float &intersection) {

	double radius = this->radius;
	vec3 length = this->center - rayCast.getOrigin();

	double val = dot(length, rayCast.getDirection());

	if (val < 0)
		return false; 

	double d = dot(length, length) - dot(val, val);

	if ((d) > (radius * radius))
		return false;

	double discriminant = sqrt((radius * radius) - d);

	float t1 = val - discriminant;
	float t2 = val + discriminant;

	if (t1 > t2)
		std::swap(t1, t2);

	if (t1 < 0) {
		t1 = t2;
		if (t1 < 0)
			return false;
	}

	intersection = t1;

	return true;
}
