#pragma once
#include <glm/glm.hpp>
#include <iostream>

using namespace glm;


namespace Graphics_Engine {

	class Transform
	{
	public:

		Transform();
		
		// Position
		vec3 GetPosition();
		void SetPosition(vec3 position);
		void SetPosition(float x, float y, float z);


		// Rotation
		vec3 GetRotation();
		void SetRotation(vec3 rotation);
		void SetRotation(float x, float y, float z);

		void Rotate(float degrees, vec3 axis);

		//Scale
		vec3 GetScale();
		void SetScale(vec3 scale);
		void SetScale(float x, float y, float z);


		//Other
		vec3 Forward();
		vec3 Up();
		vec3 Right();

		mat4 Model();

		std::string ToString();

	private:
		vec3 _position = vec3(0,0,0);
		vec3 _rotation = vec3(0,0,0);
		vec3 _scale = vec3(1, 1, 1);

		mat4 _model = mat4(1.0f);



		void UpdateModel();
	};

}


