
#include "Ray.h"

// Default Constructor
Ray::Ray() {
}

// Constructor
Ray::Ray(vec3 origin, vec3 direction) {
	this->origin = origin;
	this->direction = direction;
}

// Deconstructor
Ray::~Ray() {
}

glm::vec3 Ray::getOrigin() {
	return this->origin;
}


glm::vec3 Ray::getDirection() {
	return this->direction;
}

vec3 Ray::getPointAt(float distance) {
	return this->origin + (this->direction * distance);
}