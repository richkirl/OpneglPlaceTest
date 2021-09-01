#pragma once
#ifndef MODEL_HPP
#define MODEL_HPP
#include <vector>
class Model
{
public:
	
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	Model();
	void init(float g);
	//float* getVertices();
	//unsigned int* getIndices();
	void clean();
	~Model();
};
#endif // !MODEL_HPP



