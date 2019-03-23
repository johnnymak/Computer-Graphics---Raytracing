#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class Ray {

	public: 
		Ray();
		Ray(vec3 origin, vec3 direction);
		~Ray();

		vec3 getOrigin();
		vec3 getDirection();
		vec3 getPointAt(float distance);

	private:
		vec3 origin;
		vec3 direction;
};