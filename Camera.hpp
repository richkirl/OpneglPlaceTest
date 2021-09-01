//#pragma once
#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <glm/glm.hpp>
class Camera
{
	glm::vec3 cameraPos;// = glm::vec3(2.0f, 1.0f, 2.0f);
	glm::vec3 cameraFront;// = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 cameraUp;// = glm::vec3(0.0f, 1.0f, 0.0f);

	bool firstMouse = true;
	float yaw = -90.0f;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
	float pitch = 0.0f;
	float lastX = 1200.0f / 2.0;
	float lastY = 900.0 / 2.0;
	float fov = 45.0f;
	Camera();
	void setCameraPos(glm::vec3 cameraPos);// = glm::vec3(2.0f, 1.0f, 2.0f);
	glm::vec3 getCameraPos();
	void setCameraFront(glm::vec3 cameraFront);// = glm::vec3(0.0f, 0.0f, 1.0f);
	glm::vec3 getCameraFront();
	void setCameraUp(glm::vec3 cameraUp);// = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 getCameraUp();

	void setfirstMouse(bool firstMouse);
	bool getfirstMouse();

//	float yaw;	// yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//	float pitch;
//	float lastX;
//	float lastY;
//	float fov;
	~Camera();
};

#endif // !CAMERA_HPP



