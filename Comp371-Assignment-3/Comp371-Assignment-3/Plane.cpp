
#include "Plane.h"
#include <iostream>

// Default Constructor
Plane::Plane() {
}

// Constructor
Plane::Plane(vec3 normal, vec3 position, vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess) 
	        : Shape(ambientColor, diffusedColor, specularColor, shininess) {
	this->normal = normal;
	this->pointPosition = position;

	std::cout << "created plane: " << pointPosition.x << ", " << pointPosition.y << ", " << pointPosition.z << std::endl;
}

// Destructor
Plane::~Plane() {
}

// Getter: Return Normal
vec3 Plane::getNormal() {
	return normal;
}

// Getter: Return Point Position
vec3 Plane::getPosition() {
	return pointPosition;
}

// Plane Intersection (Based off Tutorials on ScratchPixel.com)
bool Plane::intersection(Ray rayCast, float &intersection) {

	float num = dot( (this->normal * vec3(-1) ), rayCast.getDirection());

	if (num > 1e-6) {
		vec3 dist = rayCast.getOrigin() - this->pointPosition ;
		intersection = dot(dist, this->normal) / num;

		return (intersection >= 0);
	}

	return false;
}
