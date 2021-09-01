#include "Light.hpp"

Light::Light():position(position),color(color)
{
}

Light::Light(glm::vec3 pos, glm::vec3 color)
{
    this->position = pos;
    this->color = color;
}

glm::vec3 Light::getLightPos()
{
    return position;
}

void Light::setLightPos(glm::vec3 pos)
{
    this->position = pos;
}

glm::vec3 Light::getLightColor()
{
    return color;
}

void Light::setLightColor(glm::vec3 color)
{
    this->color = color;
}

Light::~Light()
{
}
