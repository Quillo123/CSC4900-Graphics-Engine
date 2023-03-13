#include "MeshRenderer.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Window.h"

using namespace Graphics_Engine;



Graphics_Engine::MeshRenderer::MeshRenderer(Material* shader)
{
	_material = shader;
	_mesh = nullptr;
}

Graphics_Engine::MeshRenderer::MeshRenderer(Material* shader, Mesh* mesh)
{
	_material = shader;
	_mesh = mesh;
}

Graphics_Engine::MeshRenderer::MeshRenderer(Material* shader, vec3 vertices[], int vertexCount, int triangles[], int triangleCount)
{
	_material = shader;
	_mesh = new Mesh(vertexCount, vertices, triangleCount, triangles);
}

Graphics_Engine::MeshRenderer::~MeshRenderer()
{
	if (_mesh != nullptr && !_mesh->IsInUse()) {
		delete _mesh;
	}
}

void Graphics_Engine::MeshRenderer::Start()
{
	
}

void Graphics_Engine::MeshRenderer::Render()
{
	glEnable(GL_DEPTH_TEST);
	_material->Use();
	_mesh->Use();
	_material->SetMat4("model", transform.Model());
	_material->SetMat4("view", Window::main->scene.mainCam->GetViewMatrix());
	_material->SetMat4("projection", Window::main->scene.mainCam->GetProjectionMatrix());

	glDrawElements(GL_TRIANGLES, _mesh->GetTrianglesLength(), GL_UNSIGNED_INT, 0);
	_mesh->UnUse();
}

void Graphics_Engine::MeshRenderer::Update()
{
	float t = Window::main->GetTime();
	//transform.SetRotation(0, sin(t), 0);
	//transform.SetScale(sin(t)+1, cos(t)+1, sin(t)+1);
}

SceneObject* Graphics_Engine::MeshRenderer::Copy()
{
	MeshRenderer* mr = new MeshRenderer(_material, _mesh);
	mr->name = name;
	mr->transform.Position(transform.Position());
	mr->transform.Rotation(transform.Rotation());
	mr->transform.Scale(transform.Scale());
	return dynamic_cast<SceneObject*>(mr);
}

void Graphics_Engine::MeshRenderer::SetMaterial(Material* material)
{
	_material = material;
}

void Graphics_Engine::MeshRenderer::SetMesh(Mesh* mesh)
{
	_mesh = mesh;
}

Mesh* Graphics_Engine::MeshRenderer::GetSharedMesh()
{
	return _mesh;
}




