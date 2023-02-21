#include "CameraController.h"
#include <Window.h>
#include <Input.h>


void CameraController::Start()
{
	transform.SetPosition(0, 0, -3);
	transform.SetRotation(0, 0, 0);
	camera = Window::main->scene.mainCam;
}

void CameraController::Update()
{
	// Change Position
	if (Input::GetKeyPressed(KeyCode::W)) {
		inputDir += vec3(0, 0, 1) * transform.Forward();
	}
	if (Input::GetKeyPressed(KeyCode::S)) {
		inputDir += vec3(0, 0, -1) * transform.Forward();
	}
	if (Input::GetKeyPressed(KeyCode::A)) {
		inputDir += vec3(1, 0, 0);
	}
	if (Input::GetKeyPressed(KeyCode::D)) {
		inputDir += vec3(-1, 0, 0);
	}
	if (Input::GetKeyPressed(KeyCode::E)) {
		inputDir += vec3(0, -1, 0);
	}
	if (Input::GetKeyPressed(KeyCode::Q)) {
		inputDir += vec3(0, 1, 0);
	}

	// Change Rotation
	if (Input::GetKeyPressed(KeyCode::UP)) {
		camera->transform.Rotate(rotationSpeed, vec3(0, 0, 1));
	}

	if (Input::GetKeyPressed(KeyCode::C)) {
		SceneObject* sceneObject = Window::main->scene.FindObject("HelloTriangle");
		Window::main->scene.Instantiate(sceneObject, transform.GetPosition() + transform.GetRotation() * 2.0f);
	}

	

	transform.SetPosition(transform.GetPosition() + inputDir * speed * Window::main->DeltaTime());
	//transform.SetRotation(0,sin(Window::main->GetTime()), 0);
	
	camera->transform.SetPosition(-transform.GetPosition());
	camera->transform.SetRotation(-transform.GetRotation());

	inputDir = vec3(0, 0, 0);
}

SceneObject* CameraController::Copy()
{
	CameraController* obj = new CameraController();
	obj->transform.SetPosition(transform.GetPosition());
	obj->transform.SetRotation(transform.GetRotation());

	return dynamic_cast<SceneObject*>(obj);
}
