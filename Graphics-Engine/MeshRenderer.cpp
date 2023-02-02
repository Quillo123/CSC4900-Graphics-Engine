#include "MeshRenderer.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

using namespace Graphics_Engine;



Graphics_Engine::MeshRenderer::MeshRenderer(Shader* shader)
{
	_shader = shader;
	_mesh = nullptr;
}

Graphics_Engine::MeshRenderer::MeshRenderer(Shader* shader, Mesh* mesh)
{
	_shader = shader;
	_mesh = mesh;
}

Graphics_Engine::MeshRenderer::MeshRenderer(Shader* shader, vec3 vertices[], int vertexCount, int triangles[], int triangleCount)
{
	_shader = shader;
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

void Graphics_Engine::MeshRenderer::Update()
{
	_shader->Use();
	_mesh->Use();
	glDrawElements(GL_TRIANGLES, _mesh->GetTrianglesLength(), GL_UNSIGNED_INT, 0);
	_mesh->UnUse();
}

Object* Graphics_Engine::MeshRenderer::Copy()
{
	MeshRenderer* mr = new MeshRenderer(_shader, _mesh);
	mr->name = name;
	mr->transform.SetPosition(transform.GetPosition());
	mr->transform.SetRotation(transform.GetRotation());
	mr->transform.SetScale(transform.GetScale());
	return dynamic_cast<Object*>(mr);
}


