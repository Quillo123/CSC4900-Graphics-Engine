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


		Camera();

		void Start() override;

		void Update() override;

		SceneObject* Copy() override;

		mat4 GetProjectionMatrix();
		mat4 GetViewMatrix();

		void ReloadNextFrame();

	private:
		mat4 _projectionMatrix;
		CameraMode _mode;

		bool reloadProjectionMatrix = false;
		void ReloadProjectionMatrix();

	};
}



