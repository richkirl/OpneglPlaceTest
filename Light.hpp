#pragma once
#ifndef LIGHT_HPP
#define LIGHT_HPP
#include <glm/glm.hpp>

class Light
{
public:
	glm::vec3 position;
	glm::vec3 color;

	Light();
	Light(glm::vec3 pos,glm::vec3 color);
	glm::vec3 getLightPos();
	void setLightPos(glm::vec3 pos);
	glm::vec3 getLightColor();
	void setLightColor(glm::vec3 color);
	~Light();
};


#endif // !LIGHT_HPP



