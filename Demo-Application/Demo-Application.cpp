#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "Shader.h"

using namespace Graphics_Engine;
using namespace std;

int sv = 4;
vec3 vertices[] = {
     vec3(0.9f,  0.9f, 0),  // top right
     vec3(0.9f, -0.9f, 0.0f),  // bottom right
    vec3(-0.9f, -0.9f, 0.0f),  // bottom left
    vec3(-0.9f,  0.9f, 0.0f)   // top left 
};

int st = 6;
int tri[] = {
    0, 1, 3, 
    1, 2, 3
};

int main()
{
    Window* win = Window::CreateWindow();

    Shader* SampleTriangleShader = Shader::CreateShader("HelloTriangle_VS.glsl", "HelloTriangle_FS.glsl");
    Mesh* mesh = new Mesh(sv, vertices, st, tri);
    MeshRenderer* mr = new MeshRenderer(SampleTriangleShader, mesh);
    mr->name = "HelloTriangle";

    win->scene.Instantiate(dynamic_cast<Object*>(mr));

    win->StartApplication();

    delete SampleTriangleShader;
    delete win;
    return 0;
}
