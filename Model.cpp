#include "Model.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <vector>
Model::Model()
{
    init(20.0f);
}

void Model::init(float p=2.5f)
{
    
    float g = ((float)p/(float)10);//20,10,5,2.5
    //float xy = 2.0f / g;

    float pr = 1.0f;
    float mr = -1.0f;
    //int rd = glm::sin(1);
	for (float z = pr; z > mr; z -= g) {//z
		//for (float i = -1.0f; i < 1.0f; i += g) {//y
			for (float j = mr; j < pr; j += g) {//x

				for (int ijk = 0; ijk <= 5; ijk++) {
					switch (ijk) {
					case 0:
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
						break;
					case 1:
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
									this->vertices.push_back(2);
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
									this->vertices.push_back(2);
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
									this->vertices.push_back(2);
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
									this->vertices.push_back(2);
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
						break;
					case 2:
						for (int k = 0; k <= 3; k++) {

							switch (k)
							{
							case 0:
								if (j + g > pr) {
									break;
								}
								else {
									//std::cout << j << " " << z << " " << 0.0f << " " << 0.0f << 0.0f << 1.0f << std::endl;
									this->vertices.push_back(1.0f);
									this->vertices.push_back(j+1.0f);
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
									this->vertices.push_back(1.0f);
									this->vertices.push_back((j + g)+1.0f);
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
									this->vertices.push_back(1.0f);
									this->vertices.push_back((j + g)+1.0f);
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
									this->vertices.push_back(1.0f);
									this->vertices.push_back(j+1.0f);
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
						break;
					case 3:
						for (int k = 0; k <= 3; k++) {

							switch (k)
							{
							case 0:
								if (j + g > pr) {
									break;
								}
								else {
									//std::cout << j << " " << z << " " << 0.0f << " " << 0.0f << 0.0f << 1.0f << std::endl;
									this->vertices.push_back(-1.0f);
									this->vertices.push_back(j + 1.0f);
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
									this->vertices.push_back(-1.0f);
									this->vertices.push_back((j + g) + 1.0f);
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
									this->vertices.push_back(-1.0f);
									this->vertices.push_back((j + g) + 1.0f);
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
									this->vertices.push_back(-1.0f);
									this->vertices.push_back(j + 1.0f);
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
						break;
					case 4:
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
									this->vertices.push_back(z+1.0f);
									this->vertices.push_back(-1.0f);
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
									this->vertices.push_back((j + g));
									this->vertices.push_back(z+pr);
									this->vertices.push_back(-1.0f);
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
									this->vertices.push_back((j + g));
									this->vertices.push_back((z - g)+pr);
									this->vertices.push_back(-1.0f);
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
									this->vertices.push_back((z - g)+pr);
									this->vertices.push_back(-1.0f);
									this->vertices.push_back(0.0f);
									this->vertices.push_back(1.0f);
									this->vertices.push_back(0.0f);
									this->vertices.push_back(0.0f);
									this->vertices.push_back(1.0f);
									break;
								}

							}

						}
						break;
					case 5:
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
									this->vertices.push_back(z + 1.0f);
									this->vertices.push_back(1.0f);
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
									this->vertices.push_back((j + g));
									this->vertices.push_back(z + pr);
									this->vertices.push_back(1.0f);
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
									this->vertices.push_back((j + g));
									this->vertices.push_back((z - g) + pr);
									this->vertices.push_back(1.0f);
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
									this->vertices.push_back((z - g) + pr);
									this->vertices.push_back(1.0f);
									this->vertices.push_back(0.0f);
									this->vertices.push_back(1.0f);
									this->vertices.push_back(0.0f);
									this->vertices.push_back(0.0f);
									this->vertices.push_back(1.0f);
									break;
								}

							}

						}
						break;
					}
				}
			//}
			//}
		}
	}


    /*for (int i = 0; i < vertices.size()-1; i++)
    {
        std::cout << vertices[i] << " ";
    }*/


    //this->vertices =
    //{
    //    // positions         // colors
    //     1.0f, -1.0f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    //    -1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
    //     -1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f,   // top 
    //     1.0f,  1.0f, 0.0f,  0.0f, 1.0f, 1.0f   // top 
    //};
    //indices= {
    //    0, 1, 2, // first triangle
    //    1, 2, 3,  // second triangle
    //    4,5,6,
    //    5,6,7,
    //    8,9,10,
    //    9,10,11,
    //    12,13,14,
    //    13,14,15,
    //    16,17,18,
    //    17,18,19,
    //    20,21,22,
    //    21,22,23,
    //    24,25,26,
    //    25,26,27,
    //    28,29,30,
    //    29,30,31,
    //    32,33,34,
    //    33,34,35,
    //    36,37,38,
    //    37,38,39,
    //    40,41,42,
    //    41,42,43,
    //    44,45,46,
    //    45,46,47,
    //    48,49,50,
    //};
    int len = (int)((2.0f / g) * (2.0f / g))*6;
    for (int i = 0; i < len; i++) {
        //for (int j = 0; j < len / 2; j++) {
            indices.push_back(i * 4);
            indices.push_back(i * 4 + 1);
            indices.push_back(i * 4 + 3);
            indices.push_back(i * 4+1);
            indices.push_back(i * 4 + 2);
            indices.push_back(i * 4 + 3);
            // indices.push_back(i * 4 + 6);
        //}
    }
}



Model::~Model()
{
    
}

void Model::clean()
{
   // delete this->vertices;
   // delete this->indices;
}
