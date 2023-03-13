#include <iostream>
#include "Window.h"
#include "MeshRenderer.h"
#include "Shader.h"
#include "MeshMaterial.h"
#include "VoxelData.h"
#include "CameraController.h"
#include "Chunk.h"

using namespace Graphics_Engine;
using namespace std;

int main()
{
    Window* win = Window::CreateWindow();
    assert(win);

    Shader* SampleMeshShader = Shader::CreateShader("SampleVertexShader.vs.glsl", "SampleFragmentShader.fs.glsl");
    assert(SampleMeshShader);

    // Load the texture from a file
    Texture texture;
    texture.LoadTexture("MapTextureAtlas.png");
    
    // Create the mesh material
    MeshMaterial* mat = new MeshMaterial(SampleMeshShader, texture);
    mat->Use();
    mat->SetVec4("ourColor", vec4(1, 1, 1, 1));

    Chunk* chunk = new Chunk(mat);
    chunk->name = "chunk";

    for (int x = 0; x < Chunk::width; x++) {
        for (int y = 0; y < Chunk::height; y++) {
            for (int z = 0; z < Chunk::length; z++) {
                chunk->SetBlock(x, y, z, Block(y % 2 == 0 && x % 2 == 0, 4, ivec3(x, y, z)));
            }
        }
    }

    chunk->ReloadMesh();

    auto v = win->scene.Instantiate(dynamic_cast<SceneObject*>(chunk));

    auto camControl = win->scene.Instantiate(dynamic_cast<SceneObject*>(new CameraController()));
    win->scene.mainCam = dynamic_cast<Camera*>(camControl);

    cout << win->scene.mainCam->transform.ToString() << endl;
    
    win->StartApplication();

    delete SampleMeshShader;
    delete win;
    return 0;
}
