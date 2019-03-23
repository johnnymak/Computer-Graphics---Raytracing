#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

using namespace glm;

class Sphere : public Shape {

public:
	Sphere();
	Sphere(vec3 center, int radius, vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess);
	~Sphere();

	vec3 getCenter();
	int getRadius();
	bool intersection(Ray rayCast, float &intersection);

	virtual std::string getType() const { 
		return "sphere"; 
	};
	
private:
	vec3 center;
	int radius;

};