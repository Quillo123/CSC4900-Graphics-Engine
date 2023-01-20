#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#pragma once

class Window
{
public:

	//fields

	//The OpenGL Window Context
	GLFWwindow* window;

	//functions
	static Window* CreateWindow();

};

