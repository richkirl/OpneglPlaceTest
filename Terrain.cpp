#include "Terrain.hpp"
#include <iostream>

Terrain::Terrain()
{
	init(10.0f);
}

void Terrain::init(float p = 2.5f)
{
	float g = ((float)p / (float)10);//20,10,5,2.5
	//float xy = 2.0f / g;

	float pr = 1.0f;
	float mr = -1.0f;
	for (float z = pr; z > mr; z -= g) {//z
		//for (float i = -1.0f; i < 1.0f; i += g) {//y
		for (float j = mr; j < pr; j += g) {//x

			//float y = glm::perlin(x * .3f,0, z * .3f) * 2.0f;
			for (int k = 0; k <= 3; k++) {

				switch (k)
				{
				case 0:
					if (j + g > pr) {
						break;
					}
					else {
						//std::cout << j << " " << z << " " << 0.0f << " " << 0.0f << 0.0f << 1.0f << std::endl;
						this->vertices.push_back(j);
						this->vertices.push_back(0);
						this->vertices.push_back(z);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(1.0f);
						//this->vertices = {j,0,z,0.0f,0.0f,1.0f,1.0f,1.0f};
						break;
					}

				case 1:
					if (j + g > pr /*|| j == 1.0f*/) {
						break;
					}
					else {
						//std::cout << j + g << " " << z << " " << 0.0f << " " << 0.0f << 1.0f << 1.0f << std::endl;
						this->vertices.push_back(j + g);
						this->vertices.push_back(0);
						this->vertices.push_back(z);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(0.0f);
						break;
					}
				case 2:
					if (j + g > pr || z - g < mr) {
						break;
					}
					else {
						//std::cout << j + g << " " << z - g << " " << 0.0f << " " << 1.0f << 0.0f << 0.0f << std::endl;
						this->vertices.push_back(j + g);
						this->vertices.push_back(0);
						this->vertices.push_back(z - g);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(0.0f);
						break;
					}
				case 3:
					if (z - g < mr) {
						break;
					}
					else {
						//std::cout << j << " " << z - g << " " << 0.0f << " " << 0.0f << 1.0f << 0.0f << std::endl;
						this->vertices.push_back(j);
						this->vertices.push_back(0);
						this->vertices.push_back(z - g);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(1.0f);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(0.0f);
						this->vertices.push_back(1.0f);
						break;
					}
				}
			}
		}
	}
	int len = (int)((2.0f / g) * (2.0f / g)) ;
	for (int i = 0; i < len; i++) {
		//for (int j = 0; j < len / 2; j++) {
		indices.push_back(i * 4);
		indices.push_back(i * 4 + 1);
		indices.push_back(i * 4 + 3);
		indices.push_back(i * 4 + 1);
		indices.push_back(i * 4 + 2);
		indices.push_back(i * 4 + 3);
		// indices.push_back(i * 4 + 6);
	//}
	}
}

void Terrain::clean()
{
}

Terrain::~Terrain()
{
}
