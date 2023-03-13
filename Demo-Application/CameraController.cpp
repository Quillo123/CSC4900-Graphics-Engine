#include "CameraController.h"
#include <Window.h>
#include <Input.h>
#include <iostream>


void CameraController::Start()
{
	ReloadProjectionMatrix();
}

void CameraController::Update()
{


	// Change Rotation
	if (Input::GetKeyPressed(KeyCode::UP)) {
		Pitch += rotationSpeed * Window::main->DeltaTime();
		if (Pitch > 89) Pitch = 89;
		if (Pitch < -89) Pitch = -89;
	}
	if (Input::GetKeyPressed(KeyCode::DOWN)) {
		Pitch -= rotationSpeed * Window::main->DeltaTime();
		if (Pitch > 89) Pitch = 89;
		if (Pitch < -89) Pitch = -89;
	}
	if (Input::GetKeyPressed(KeyCode::LEFT)) {
		Yaw -= rotationSpeed * Window::main->DeltaTime();
	}
	if (Input::GetKeyPressed(KeyCode::RIGHT)) {
		Yaw += rotationSpeed * Window::main->DeltaTime();
	}


	vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);
	//// also re-calculate the Right and Up vector
	Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	Up = glm::normalize(glm::cross(Right, Front));



	transform.Rotation(normalize(front));


	// Change Position
	if (Input::GetKeyPressed(KeyCode::W)) {
		inputDir += Front;
	}
	if (Input::GetKeyPressed(KeyCode::S)) {
		inputDir -= Front;
	}
	if (Input::GetKeyPressed(KeyCode::A)) {
		inputDir -= Right;
	}
	if (Input::GetKeyPressed(KeyCode::D)) {
		inputDir += Right;
	}
	if (Input::GetKeyPressed(KeyCode::E)) {
		inputDir += WorldUp;
	}
	if (Input::GetKeyPressed(KeyCode::Q)) {
		inputDir -= WorldUp;
	}

	transform.Position(transform.Position() + inputDir * speed * Window::main->DeltaTime());

	if (Input::GetKeyPressed(KeyCode::C)) {
		SceneObject* sceneObject = Window::main->scene.FindObject("chunk");
		Window::main->scene.Instantiate(sceneObject, transform.Position() + transform.Rotation() * 2.0f);
	}

	inputDir = vec3(0, 0, 0);

	if (reloadProjectionMatrix) {
		ReloadProjectionMatrix();
	}
}

SceneObject* CameraController::Copy()
{
	CameraController* obj = new CameraController();
	obj->transform.Position(transform.Position());
	obj->transform.Rotation(transform.Rotation());

	return dynamic_cast<SceneObject*>(obj);
}
