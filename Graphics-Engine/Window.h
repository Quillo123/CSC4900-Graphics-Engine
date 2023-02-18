#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Scene.h"

namespace Graphics_Engine {

	class Window
	{

	public:

		static Window* main;

		//fields
		Scene scene = Scene();
 
		//The OpenGL Window Context
		GLFWwindow* window;

		//functions

		//Creates and initializes a new window
		static Window* CreateWindow();

		//Starts the application loop
		int StartApplication();

		~Window();

		ivec2 Resolution();


		//Helpers 
		float lastTime = 0;

		float GetTime();
		float DeltaTime();
	private:
		ivec2 _resolution;

		//Called whenever the window is resized	
		void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		void OnWindowInput();
	};



}


