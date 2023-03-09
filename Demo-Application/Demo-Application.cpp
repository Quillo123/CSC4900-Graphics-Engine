#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "MeshMaterial.h"
#include "VoxelData.h"
#include "CameraController.h"

using namespace Graphics_Engine;
using namespace std;

int main()
{
    Window* win = Window::CreateWindow();
    assert(win);

    Shader* SampleMeshShader = Shader::CreateShader("SampleVertexShader.vs.glsl", "SampleFragmentShader.fs.glsl");
    assert(SampleMeshShader);


    // Set the renderer color
    //vec4 color = vec4(1, 1, 1, 1);
    //SampleTriangleShader->Use();
    //SampleTriangleShader->SetVec4("ourColor", color);

    // Load the texture from a file
    Texture texture;
    texture.LoadTexture("004_stone.png");
    
    // Create the mesh material
    MeshMaterial* mat = new MeshMaterial(SampleMeshShader, texture);
    mat->Use();
    mat->SetVec4("ourColor", vec4(1, 1, 1, 1));
    
    /// Create a Cube
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

    MeshRenderer* mR = new MeshRenderer(mat, mesh);
    mR->name = "HelloTriangle1";

    auto cam = win->scene.Instantiate(dynamic_cast<SceneObject*>(new Camera()));
    win->scene.mainCam = dynamic_cast<Camera*>(cam);
    win->scene.mainCam->transform.SetPosition(vec3(0, 0, -4));
    cout << win->scene.mainCam->transform.ToString();

    auto camControl = win->scene.Instantiate(dynamic_cast<SceneObject*>(new CameraController()));

    //mr->transform.SetRotation(vec3(0.3f, 0, 0.3f));

    auto v = win->scene.Instantiate(dynamic_cast<SceneObject*>(mr));
    auto c = win->scene.Instantiate(dynamic_cast<SceneObject*>(mR), vec3(2,0,0));
    cout << v->transform.ToString() << endl;
    cout << c->transform.ToString() << endl;

    win->StartApplication();

    delete SampleMeshShader;
    delete win;
    return 0;
}
