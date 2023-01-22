#include <glm/glm.hpp>

using namespace glm;

#pragma once

namespace Graphics_Engine {

	class Transform
	{
	public:
		
		vec3 GetPosition();
		void SetPosition(vec3 position);


		vec3 GetRotation();
		void SetRotation(vec3 rotation);

		vec3 GetScale();
		void SetScale(vec3 scale);

	private:
		vec3 _position = vec3(0,0,0);
		vec3 _rotation = vec3(0,0,0);
		vec3 _scale = vec3(1, 1, 1);


	};

}


