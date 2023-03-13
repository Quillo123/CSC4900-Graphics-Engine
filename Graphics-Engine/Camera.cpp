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
	vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);
	// also re-calculate the Right and Up vector
	Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	Up = glm::normalize(glm::cross(Right, Front));

	if (reloadProjectionMatrix) {
		ReloadProjectionMatrix();
	}
}

SceneObject* Graphics_Engine::Camera::Copy()
{
	Camera* obj = new Camera();
	obj->transform.Position(transform.Position());
	obj->transform.Rotation(transform.Rotation());

	return dynamic_cast<SceneObject*>(obj);
}

mat4 Graphics_Engine::Camera::GetProjectionMatrix()
{
	return _projectionMatrix;
}

mat4 Graphics_Engine::Camera::GetViewMatrix()
{
	return glm::lookAt(transform.Position(), transform.Position() + Front, Up);
}

void Graphics_Engine::Camera::ReloadNextFrame()
{
	reloadProjectionMatrix = true;
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


