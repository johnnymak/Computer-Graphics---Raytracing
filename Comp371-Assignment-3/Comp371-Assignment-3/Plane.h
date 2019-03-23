#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shape.h"

using namespace glm;

class Plane : public Shape {

	public:
		Plane();
		Plane(vec3 normal, vec3 position, vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess);
		~Plane();

		vec3 getNormal();
		vec3 getPosition();
		bool intersection(Ray rayCast, float &intersection);

		virtual std::string getType() const {
			return "plane";
		};

	private:
		vec3 normal;
		vec3 pointPosition;

};