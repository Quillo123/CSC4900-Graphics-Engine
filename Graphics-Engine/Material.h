#include "Shader.h"

#pragma once

namespace Graphics_Engine {
	class Material
	{
	public:

		Material(Shader* shader) {
			_shader = shader;
		}

		virtual void Use();

	protected:
		Shader* _shader;

		Material();


	};
}



