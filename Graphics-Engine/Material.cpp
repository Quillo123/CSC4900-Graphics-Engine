#include "Material.h"

void Graphics_Engine::Material::Use()
{
	_shader->Use();
}

Graphics_Engine::Material::Material()
{
	_shader = nullptr;
}
