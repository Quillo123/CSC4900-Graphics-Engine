#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "MeshMaterial.h"
#include "VoxelData.h"
#include "CameraController.h"

using namespace Graphics_Engine;
using namespace std;

//int sv = 4;
//vec3 vertices[] = {
//     vec3(0.5f, 0.5f, 0),  // top right
//     vec3(0.5f, -0.5f, 0.0f),  // bottom right
//     vec3(-0.5f, -0.5f, 0.0f),  // bottom left
//     vec3(-0.5f,  0.5f, 0.0f)   // top left 
//};
//
//int st = 6;
//int tri[] = {
//    0, 1, 3, 
//    1, 2, 3
//};
//
//int su = 4;
//vec2 uvs[] = {
//    vec2(1.0f,1.0f),
//    vec2(1.0f,0.0f),
//    vec2(0.0f,0.0f),
//    vec2(0.0f,1.0f)
//};

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
    mat->SetVec4("ourColor", vec4(0, 1, 0, 0));

    vec3 vertices[4 * 6];
    vec2 uvs[4 * 6];
    int tris[6 * 6];

    int vcount = 0;
    int tcount = 0;
    int ucount = 0;
    int ind = 0;
    for (int i = 0; i < 6; i++) {
        vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][0]];
        vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][1]];
        vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][2]];
        vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][3]];
        uvs[ucount++] = VoxelData::uvs[0];
        uvs[ucount++] = VoxelData::uvs[1];
        uvs[ucount++] = VoxelData::uvs[2];
        uvs[ucount++] = VoxelData::uvs[3];
        tris[tcount++] = ind+0;
        tris[tcount++] = ind+1;
        tris[tcount++] = ind+2;
        tris[tcount++] = ind + 2;
        tris[tcount++] = ind + 1;
        tris[tcount++] = ind + 3;
        ind += 4;
    }

    Mesh* mesh = new Mesh(4*6, vertices, 6*6, tris);
    mesh->SetUvs0(4*6, uvs);


    MeshRenderer* mr = new MeshRenderer(mat, mesh);
    mr->name = "HelloTriangle";

    auto cam = win->scene.Instantiate(dynamic_cast<SceneObject*>(new Camera()));
    win->scene.mainCam = dynamic_cast<Camera*>(cam);
    win->scene.mainCam->transform.SetPosition(vec3(0, 0, -4));
    cout << win->scene.mainCam->transform.ToString();

    auto camControl = win->scene.Instantiate(dynamic_cast<SceneObject*>(new CameraController()));

    //mr->transform.SetRotation(vec3(0.3f, 0, 0.3f));
    cout << mr->transform.ToString();

    win->scene.Instantiate(dynamic_cast<SceneObject*>(mr));

    win->StartApplication();

    delete SampleTriangleShader;
    delete win;
    return 0;
}
