
#include "FileReader.h"

using namespace std;

// Default Constructor
FileReader::FileReader() {
	cout << "Default FileReader Constructor Called! " << endl;
}

// Constructor
FileReader::FileReader(Camera** camera, vector<Shape*>* shapes, vector<Light*>* lights) {
	this->camera = camera;
	this->shapes = shapes;
	this->lights = lights;
}

// Destructor
FileReader::~FileReader() {
	
}

// Read File Function
void FileReader::readFile(string fileLocation) {

	ifstream myFile(fileLocation);

	string object = "";

	int numOfObjects;
	myFile >> numOfObjects >> ws;

	// ============ Creating Objects and Shapes ================
	for (int i = 0; i < numOfObjects; i++) {
		getline(myFile, object);

		// =========== Camera Object ============= //
		if (object == "camera") {
			string temp;
			float x, y, z;

			myFile >> temp >> x >> y >> z;

			glm::vec3 position(x, y, z);

			myFile >> temp >> x >> ws;
			myFile >> temp >> y >> ws;
			myFile >> temp >> z >> ws;

			*camera = new Camera(position, x, y, z);
		}

		// =========== Plane Shape ============= //
		else if (object == "plane") {
			string temp;
			float x, y, z;

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 nor(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 pos(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 amb(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 dif(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 spe(x, y, z);

			myFile >> temp >> x >> ws;

			Shape* plane = new Plane(nor, pos, amb, dif, spe, x);

			shapes->push_back(plane);
		}

		// =========== Triangle Shape ============= //
		else if (object == "triangle") {
			string temp;
			float x, y, z;

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 v1(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 v2(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 v3(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 amb(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 dif(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 spe(x, y, z);

			myFile >> temp >> x >> ws;

			Shape* triangle = new Triangle(v1, v2, v3, amb, dif, spe, x);

			shapes->push_back(triangle);
		}

		// =========== Sphere Shape ============= //
		else if (object == "sphere") {
			string temp;
			float x, y, z, radius;

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 pos(x, y, z);

			myFile >> temp >> radius;

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 amb(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 dif(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 spe(x, y, z);

			myFile >> temp >> x >> ws;

			Shape* sphere = new Sphere(pos, radius, amb, dif, spe, x);

			shapes->push_back(sphere);
		}

		// =========== Light Object ============= //
		else if (object == "light") {
			string temp;
			float x, y, z;

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 pos(x, y, z);

			myFile >> temp >> x >> y >> z >> ws;
			glm::vec3 color(x, y, z);


			Light* light = new Light(pos, color);

			lights->push_back(light);
		}

	}

	myFile.close();
}