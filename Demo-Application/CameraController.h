#pragma once
#include <SceneObject.h>
#include <Camera.h>

using namespace Graphics_Engine;

class CameraController : public Camera
{
public:
	float speed = 500;
	float rotationSpeed = 10000;
	vec3 inputDir = vec3(0, 0, 0);

	void Start() override;
	void Update() override;
	SceneObject* Copy() override;

};

