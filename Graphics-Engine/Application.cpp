#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"

int main()
{
    Window* win = Window::CreateWindow();
    if (win == nullptr) {
        std::cout << "Could not create a window context" <<std::endl;
    }

    return 0;
}