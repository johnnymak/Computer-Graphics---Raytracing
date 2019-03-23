#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

using namespace glm;

class Triangle : public Shape {

public:
	Triangle();
	Triangle(vec3 first, vec3 second, vec3 third, vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess);
	~Triangle();

	vec3 getVertexOne();
	vec3 getVertexTwo();
	vec3 getVertexThree();
	bool intersection(Ray rayCast, float &intersection);

	virtual std::string getType() const {
		return "triangle";
	}
	
private:
	vec3 vertexOne;
	vec3 vertexTwo;
	vec3 vertexThree;

	
};