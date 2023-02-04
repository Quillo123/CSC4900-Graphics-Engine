#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "MeshMaterial.h"

using namespace Graphics_Engine;
using namespace std;

int sv = 4;
vec3 vertices[] = {
     vec3(0.5f, 0.5f, 0),  // top right
     vec3(0.5f, -0.5f, 0.0f),  // bottom right
     vec3(-0.5f, -0.5f, 0.0f),  // bottom left
     vec3(-0.5f,  0.5f, 0.0f)   // top left 
};

int st = 6;
int tri[] = {
    0, 1, 3, 
    1, 2, 3
};

int su = 4;
vec2 uvs[] = {
    vec2(1.0f,1.0f),
    vec2(1.0f,0.0f),
    vec2(0.0f,0.0f),
    vec2(0.0f,1.0f)
};

int main()
{
    Window* win = Window::CreateWindow();

    Shader* SampleTriangleShader = Shader::CreateShader("HelloTriangle_VS.glsl", "HelloTriangle_FS.glsl");
    
    vec4 color = vec4(1, 1, 1, 1);
    SampleTriangleShader->Use();
    SampleTriangleShader->SetVec4("ourColor", color);

    Texture texture;
    texture.LoadTexture("004_stone.png");
    
    MeshMaterial* mat = new MeshMaterial(SampleTriangleShader, texture);

    Mesh* mesh = new Mesh(sv, vertices, st, tri);
    mesh->SetUvs0(4, uvs);

    MeshRenderer* mr = new MeshRenderer(mat, mesh);
    mr->name = "HelloTriangle";

    win->scene.Instantiate(dynamic_cast<Object*>(mr));

    win->StartApplication();

    delete SampleTriangleShader;
    delete win;
    return 0;
}
