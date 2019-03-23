
#include "Camera.h"
#include <iostream>

// Default Constructor
Camera::Camera() {
	std::cout << "Default Constructor Called! " << std::endl;
}

// Constructor
Camera::Camera(vec3 position, int fov, int focal_length, float aspect_ratio) {
	this->position = position;
	this->fov = fov;
	this->focal_length = focal_length;
	this->aspect_ratio = aspect_ratio;

	std::cout << "created camera: " << position.x << ", " << position.y << ", " << position.z << std::endl;
}

// Destructor
Camera::~Camera() {
}

// Setter: Set the Focal Length (FOR TESTING) 
void Camera::setFocalLength(int length) {
	this->focal_length = length;
}

// Getter: Returns Vec3 Camera Position
glm::vec3 Camera::getPosition() {
	return position;
}

// Getter: Get FOV
int Camera::getFov() {
	return fov;
}

// Getter: Get Focal Length
int Camera::getFocalLength() {
	return focal_length;
}

// Getter: Get Aspect Ratio
float Camera::getAspectRatio() {
	return aspect_ratio;
}