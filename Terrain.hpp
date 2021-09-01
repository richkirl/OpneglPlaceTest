#pragma once
#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <vector>
class Terrain
{
public:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	Terrain();

	void init(float p);
	void clean();

	~Terrain();
};


#endif // !TERRAIN_HPP

//#include <vector>
//class Model
//{
//public:
//
//	std::vector<float> vertices;
//	std::vector<unsigned int> indices;
//	Model();
//	void init(float g);
//	//float* getVertices();
//	//unsigned int* getIndices();
//	void clean();
//	~Model();
//};

