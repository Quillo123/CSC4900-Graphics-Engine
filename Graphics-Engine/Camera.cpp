#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"

using namespace Graphics_Engine;

Graphics_Engine::Camera::Camera()
{
	_mode = CameraMode::PERSPECTIVE;
}

void Graphics_Engine::Camera::Start()
{
	ReloadProjectionMatrix();
}

void Graphics_Engine::Camera::Update()
{
	
}

SceneObject* Graphics_Engine::Camera::Copy()
{
	Camera* obj = new Camera();
	obj->transform.SetPosition(transform.GetPosition());
	obj->transform.SetRotation(transform.GetRotation());

	return dynamic_cast<SceneObject*>(obj);
}

mat4 Graphics_Engine::Camera::GetProjectionMatrix()
{
	return _projectionMatrix;
}

mat4 Graphics_Engine::Camera::GetViewMatrix()
{
	return inverse(transform.Model());
}

void Graphics_Engine::Camera::ReloadProjectionMatrix()
{
	ivec2 res = Window::main->Resolution();
	_projectionMatrix = mat4(1.0f);

	if (_mode == CameraMode::ORTHOGRAPHIC) {
		_projectionMatrix = glm::ortho(0.0f, (float)res.x, 0.0f, (float)res.y, 0.1f, 100.0f);
	}
	else {
		_projectionMatrix = glm::perspective(glm::radians(45.0f), (float)res.x / (float)res.y, 0.1f, 100.0f);
	}
}


