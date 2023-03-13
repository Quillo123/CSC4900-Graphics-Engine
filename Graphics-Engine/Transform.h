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
		vec3 Position();
		void Position(vec3 position);
		void Position(float x, float y, float z);


		// Rotation
		vec3 Rotation();
		void Rotation(vec3 rotation);
		void Rotation(float x, float y, float z);

		void Rotate(float degrees, vec3 axis);

		//Scale
		vec3 Scale();
		void Scale(vec3 scale);
		void Scale(float x, float y, float z);


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


