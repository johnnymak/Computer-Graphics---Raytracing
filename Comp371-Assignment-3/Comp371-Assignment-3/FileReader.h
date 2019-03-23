#pragma once

#include "CommonInclude.h"

using namespace std;

class FileReader {

	public:	
		FileReader();
		FileReader(Camera** camera, vector<Shape*> *shapes, vector<Light*> *lights);

		~FileReader();

		void readFile(string fileLocation);

	private:
		Camera** camera;
		vector<Shape*>* shapes;
		vector<Light*>* lights;

};
