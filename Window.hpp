#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP
struct GLFWwindow;
class Window
{
public:
	//Make window(GLFW)
	GLFWwindow* window;
public:
	Window();
	int initglfw();
	int createWindow();
	int initGlew();
	GLFWwindow* getWindow();
	void clean();

	~Window();
};
#endif // !WINDOW_HPP



