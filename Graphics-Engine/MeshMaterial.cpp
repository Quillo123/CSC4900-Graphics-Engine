#include "MeshMaterial.h"

Graphics_Engine::MeshMaterial::MeshMaterial(Shader* shader)
{
	_shader = shader;
}

Graphics_Engine::MeshMaterial::MeshMaterial(Shader* shader, Texture tex)
{
	_shader = shader;
	texture = tex;
}

void Graphics_Engine::MeshMaterial::Use()
{
	_shader->Use();
	texture.Use();
}
