#include "Window.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


	Window::Window()
	{
		// glfw: initialize and configure
		// ------------------------------
		glfwInit();
        glfwDefaultWindowHints();
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		// glfw window creation
		// --------------------
		window = glfwCreateWindow(1200, 900, "LearnOpenGL", NULL, NULL);
		if (window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);
		///glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		// glad: load all OpenGL function pointers
		// ---------------------------------------
		glewExperimental = true;
		glewInit();

	}

	int Window::initglfw()
	{
		if (!glfwInit())
		{
			std::cerr << "Couldt Load GLFWinit\n";
			clean();
			return -1;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


		return 0;
	}

	int Window::createWindow()
	{
		this->window = glfwCreateWindow(1200, 900, "Title", NULL, NULL);
		if (!this->window)
		{
			std::cerr << "Couldt create Window GLFW\n";
			clean();
			return -1;
		}
		glfwMakeContextCurrent(this->window);
		return 0;
	}

	int Window::initGlew()
	{
		glewExperimental = true;
		glewInit();
		return 0;
	}

	void Window::clean()
	{
		glfwDestroyWindow(this->window);
		glfwTerminate();
	}

	GLFWwindow* Window::getWindow()
	{
		return this->window;
	}

	Window::~Window()
	{
		glfwTerminate();
	}
