#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cassert>

using namespace Graphics_Engine;

Window* Window::CreateWindow()
{
    Window* win = new Window();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    win->window = glfwCreateWindow(1920, 1080, "LearnOpenGL", NULL, NULL);
    if (win->window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(win->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

    glViewport(0, 0, 1920, 1080);

    //Setting the window user pointer allows us to acces it from the GLFW object
    //using glfwGetWindowUserPointer(window)
    glfwSetWindowUserPointer(win->window, &win);

    //Wraps the framebuffer_size_callback
    auto window_size_callback = [](GLFWwindow* window, int w, int h) {
        Window* obj = static_cast<Window*>(glfwGetWindowUserPointer(window));
        assert(obj);
        obj->framebuffer_size_callback(window, w, h);
    };



    return win;
}

int Graphics_Engine::Window::StartApplication()
{
    scene.Start();
    while (!glfwWindowShouldClose(window))
    {
        OnWindowInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        scene.Update();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

Graphics_Engine::Window::~Window()
{
    
}

void Graphics_Engine::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Graphics_Engine::Window::OnWindowInput()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


