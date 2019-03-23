#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include "Ray.h"

using namespace glm;

class Shape {

	public:
		Shape();
		Shape(vec3 ambientColor, vec3 diffusedColor, vec3 specularColor, float shininess);

		virtual ~Shape();

		vec3 getAmbientColor();
		vec3 getDiffusedColor();
		vec3 getSpecularColor();
		float getShininess();

		virtual bool intersection(Ray rayCast, float &distance) = 0;
		virtual std::string getType() const = 0;

	protected:
		vec3 ambientColor;
		vec3 diffusedColor;
		vec3 specularColor;
		float shininess;
};