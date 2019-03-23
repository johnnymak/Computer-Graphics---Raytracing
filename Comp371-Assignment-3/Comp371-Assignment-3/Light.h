#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class Light {

	public:
		Light();
		Light(vec3 position, vec3 lightColor);
		~Light();

		vec3 getPosition();
		vec3 getLightColor();

	private:
		vec3 position; 
		vec3 lightColor;
	
};
