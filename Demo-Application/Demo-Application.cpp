#include <iostream>
#include "Window.h"

using namespace Graphics_Engine;
using namespace std;

int main()
{
    Window* win = Window::CreateWindow();

    win->StartApplication();

    delete win;
    return 0;
}
