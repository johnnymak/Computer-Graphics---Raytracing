#pragma once

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class Camera {

	public:
		Camera();
		Camera(vec3 position, int fov, int focal_length, float aspect_ratio);
		~Camera();
		
		void setFocalLength(int length);
		vec3 getPosition();
		int getFov();
		int getFocalLength();
		float getAspectRatio();

	private:
		vec3 position;
		int fov;
		int focal_length;
		float aspect_ratio;

};