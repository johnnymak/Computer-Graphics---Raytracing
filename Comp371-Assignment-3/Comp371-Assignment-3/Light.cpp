
#include "Light.h"
#include <iostream>


// Default Constructor
Light::Light() {
	std::cout << "Default Constructor Called" << std::endl;
}

// Constructor
Light::Light(vec3 position, vec3 lightColor) {
	this->position = position;
	this->lightColor = lightColor;

	std::cout << "created light: " << position.x << ", " << position.y << ", " << position.z << std::endl;
}

// Deconstructor
Light::~Light() {
}

// Getter: Return Position
vec3 Light::getPosition() {
	return position;
}

// Getter: Return Light Color
vec3 Light::getLightColor() {
	return lightColor;
}