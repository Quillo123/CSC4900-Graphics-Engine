#pragma once
#include <glm/glm.hpp>
#include "SceneObject.h"

using namespace glm;

namespace Graphics_Engine {
	class Camera :
		public SceneObject
	{
	public:
		enum CameraMode {
			ORTHOGRAPHIC,
			PERSPECTIVE
		};

		vec3 Front;
		vec3 Up;
		vec3 Right;
		vec3 WorldUp = vec3(0,1,0);
		// euler Angles
		float Yaw;
		float Pitch;
		// camera options
		float MovementSpeed;
		float MouseSensitivity;
		float Zoom;

		Camera();


		void Start() override;

		void Update() override;

		SceneObject* Copy() override;

		mat4 GetProjectionMatrix();
		mat4 GetViewMatrix();

		void ReloadNextFrame();
	protected:
		mat4 _projectionMatrix;
		CameraMode _mode;

		bool reloadProjectionMatrix = false;
		void ReloadProjectionMatrix();

	};
}



