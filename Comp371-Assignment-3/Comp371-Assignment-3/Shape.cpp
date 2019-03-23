
#include "Shape.h"
#include <iostream>

// Default Constructor
Shape::Shape() {
	std::cout << "Default Constructor Called! " << std::endl;
}

// Constructor
Shape::Shape(vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess) {
	this->ambientColor = ambientColor;
	this->diffusedColor = diffusedColor;
	this->specularColor = specularColor;
	this->shininess = shininess;
}

// Destructor
Shape::~Shape() {
}

// Getter: Return Ambient Color
vec3 Shape::getAmbientColor() {
	return ambientColor;
}

// Getter: Return Diffused Color
vec3 Shape::getDiffusedColor() {
	return diffusedColor;
}

// Getter: Return Specular Color
vec3 Shape::getSpecularColor() {
	return specularColor;
}

// Getter: Return Shininess
float Shape::getShininess() {
	return shininess;
}