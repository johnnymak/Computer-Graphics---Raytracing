
#include "CommonInclude.h"


using namespace std;


// ============ Function Prototypes ============
glm::vec3 findDirection(int pointX, int pointY, int width, int height, float fov, float aspectRatio, glm::vec3 origin);
float valueClamp(float value);


// ============== Scenes File Location ================= //

//const string FILE_LOCATION = "txt/scene1.txt";
//const string FILE_LOCATION = "txt/scene2.txt";
//const string FILE_LOCATION = "txt/scene3.txt";
//const string FILE_LOCATION = "txt/scene4.txt";
//const string FILE_LOCATION = "txt/scene5.txt";
//const string FILE_LOCATION = "txt/scene6.txt";
//const string FILE_LOCATION = "txt/scene7.txt";
//const string FILE_LOCATION = "txt/scene8.txt";
//const string FILE_LOCATION = "txt/scene9.txt";
const string FILE_LOCATION = "txt/scene10.txt";


// ======= Class Members =======
Camera* camera; 
vector<Shape*> shapes;
vector<Light*> lights;

int height, width, focalLength;
float fovX, fovY, aspectRatio;
vec3 fDirection;


// ========================= Main Method ============================= //
int main() {

	// Reading the File
	FileReader fileR(&camera, &shapes, &lights);
	fileR.readFile(FILE_LOCATION);

	// Change Focal Length (TESTING)
	//camera->setFocalLength(250);
	
	fovY = camera->getFov();
	fovX = 2 * atan(tan(fovX/2) * camera->getAspectRatio());
	focalLength = camera->getFocalLength();

	// Calculate the Window Dimensions
	height = 2 * (focalLength) * tan(fovY / 2 * PI / 180.0);
	width = height * camera->getAspectRatio();

	vec3 cameraPos = camera->getPosition();

	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;


	// ======= Creates image with three Channels ======= 
	cimg_library::CImg<float> image(width, height, 1, 3, 0);


	// ================ Compute Color for each Pixel ================ 

	// For each pixel
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {

			// Find direction vector and create the ray
			fDirection = findDirection(i, j, width, height, fovY, camera->getAspectRatio(), cameraPos);
			Ray rayCast(cameraPos, fDirection);

			float tempDist;
			float currentDist = 0;
			int objectIndex;
			bool intersected = false;

			// Check Each Shape for Intersection and Find Closest Shape
			for (int k = 0; k < shapes.size(); k++) {

				if (shapes.at(k)->intersection(rayCast, tempDist)) {
					if (!intersected) {
						objectIndex = k;
						currentDist = tempDist;
						intersected = true;
					}

					else if (tempDist < currentDist) {
						objectIndex = k;
						currentDist = tempDist;
					}

				}
			}

			// ====== Color the pixel ====== 
			if (intersected) {

				// Initial Ambient Color
				vec3 color = shapes.at(objectIndex)->getAmbientColor();

				// Check for light source
				vec3 intersectionPoint = currentDist * fDirection;
				bool hasDirectLight = true;
				
				//Check for each light source
				for (int l = 0; l < lights.size(); l++) {

					vec3 lightDirection = normalize(lights.at(l)->getPosition() - intersectionPoint);
					Ray lightRay(intersectionPoint, lightDirection);
					float uselessDist;

					// Check for each shape
					for (int s = 0; s < shapes.size(); s++) {
						if (shapes.at(s)->intersection(lightRay, uselessDist)) {
							hasDirectLight = false;
						}
					}

					// No object between point and light source
					if (hasDirectLight) {

						// Diffused Light
						color += (lights.at(l)->getLightColor() * shapes.at(objectIndex)->getDiffusedColor()); 

						// Specular Light
						color += (lights.at(l)->getLightColor() * shapes.at(objectIndex)->getSpecularColor());
						
					}
				}


				// Setting Final Color
				image(i, j, 0) = color.x;
				image(i, j, 1) = color.y;
				image(i, j, 2) = color.z;
			}
		}
	}


	// Save Image in .BMP
	image.normalize(0, 255).save("Rendered/Scene.bmp");


	// Display Image on Screen
	cimg_library::CImgDisplay main_disp(image, "Scene");
	while (main_disp.is_closed()) {
		main_disp.wait();
	}


	
	// ================ Deleting our objects ================
	delete camera;
	
	for (int i = 0; i < shapes.size(); i++) {
		delete shapes.at(i);
	}

	for (int i = 0; i < lights.size(); i++) {
		delete lights.at(i);
	}

	system("PAUSE");
	return 0;
}

// Function to find the direction vector with the Camera as origin
glm::vec3 findDirection(int pointX, int pointY, int width, int height, float fov, float aspectRatio, glm::vec3 origin) {

	float scale = tan(fov / 2 * PI / 180);
	float worldSpaceX = (2 * ((pointX + 0.5) / width) - 1) * scale * aspectRatio;
	float worldSpaceY = ( (1 - (2 * (pointY + 0.5) / height))) * scale;

	glm::vec3 direction(worldSpaceX, worldSpaceY, -1);

	return normalize(direction - origin); 
}

// Clamp function to limit values within a range
float valueClamp(float value) {
	if (value >= 1.0f)
		return 1.0f;
	else if (value <= 0.0f)
		return 0.0f;
}