#include "Material.h"

void Graphics_Engine::Material::SetBool(const std::string& name, bool value)
{
	_shader->SetBool(name, value);
}

void Graphics_Engine::Material::SetInt(const std::string& name, int value)
{
	_shader->SetInt(name, value);
}

void Graphics_Engine::Material::SetFloat(const std::string& name, float value)
{
	_shader->SetFloat(name, value);
}

void Graphics_Engine::Material::SetVec3(const std::string& name, glm::vec3 value)
{
	_shader->SetVec3(name, value);
}

void Graphics_Engine::Material::SetVec4(const std::string& name, glm::vec4 value)
{
	_shader->SetVec4(name, value);
}

void Graphics_Engine::Material::SetMat4(const std::string& name, glm::mat4 value)
{
	_shader->SetMat4(name, value);
}

void Graphics_Engine::Material::Use()
{
	_shader->Use();
}

Graphics_Engine::Material::Material()
{
	_shader = nullptr;
}
