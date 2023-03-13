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
    
    ///// Create a Cube
    //vec3 vertices[4 * 6];
    //vec2 uvs[4 * 6];
    //int tris[6 * 6];

    //int vcount = 0;
    //int tcount = 0;
    //int ucount = 0;
    //int ind = 0;
    //for (int i = 0; i < 6; i++) {
    //    vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][0]];
    //    vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][1]];
    //    vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][2]];
    //    vertices[vcount++] = VoxelData::Vertices[VoxelData::Triangles[i][3]];
    //    uvs[ucount++] = VoxelData::uvs[0];
    //    uvs[ucount++] = VoxelData::uvs[1];
    //    uvs[ucount++] = VoxelData::uvs[2];
    //    uvs[ucount++] = VoxelData::uvs[3];
    //    tris[tcount++] = ind+0;
    //    tris[tcount++] = ind+1;
    //    tris[tcount++] = ind+2;
    //    tris[tcount++] = ind + 2;
    //    tris[tcount++] = ind + 1;
    //    tris[tcount++] = ind + 3;
    //    ind += 4;
    //}

    //Mesh* mesh = new Mesh(4*6, vertices, 6*6, tris);
    //mesh->SetUvs0(4*6, uvs);

    Chunk* chunk = new Chunk(mat);
    chunk->name = "chunk";

    for (int x = 0; x < Chunk::width; x++) {
        for (int y = 0; y < Chunk::height; y++) {
            for (int z = 0; z < Chunk::length; z++) {
                chunk->SetBlock(x, y, z, Block(y % 2 == 0 && x % 2 == 0, 0, ivec3(x, y, z)));
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
