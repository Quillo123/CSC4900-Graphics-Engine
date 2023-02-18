#include "CameraController.h"
#include <Window.h>


void CameraController::Start()
{
	camera = Window::main->scene.mainCam;
}

void CameraController::Update()
{
	// Change Position
	if (Window::main->GetKeyPressed(GLFW_KEY_W)) {
		inputDir += vec3(0, 0, 1);
	}
	if (Window::main->GetKeyPressed(GLFW_KEY_S)) {
		inputDir += vec3(0, 0, -1);
	}
	if (Window::main->GetKeyPressed(GLFW_KEY_A)) {
		inputDir += vec3(1, 0, 0);
	}
	if (Window::main->GetKeyPressed(GLFW_KEY_D)) {
		inputDir += vec3(-1, 0, 0);
	}
	if (Window::main->GetKeyPressed(GLFW_KEY_E)) {
		inputDir += vec3(0, -1, 0);
	}
	if (Window::main->GetKeyPressed(GLFW_KEY_Q)) {
		inputDir += vec3(0, 1, 0);
	}

	// Change Rotation
	if (Window::main->GetKeyPressed(GLFW_KEY_UP)) {
		camera->transform.Rotate(rotationSpeed, vec3(0, 0, 1));
	}


	camera->transform.SetPosition(camera->transform.GetPosition() + inputDir * speed * Window::main->DeltaTime());
	inputDir = vec3(0, 0, 0);
}

SceneObject* CameraController::Copy()
{
	CameraController* obj = new CameraController();
	obj->transform.SetPosition(transform.GetPosition());
	obj->transform.SetRotation(transform.GetRotation());

	return dynamic_cast<SceneObject*>(obj);
}
