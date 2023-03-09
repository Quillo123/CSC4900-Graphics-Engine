#pragma once
#include "Shader.h"


namespace Graphics_Engine {
	class Material
	{
	public:

		Material(Shader* shader) {
			_shader = shader;
		}

		void SetBool(const std::string& name, bool value);
		void SetInt(const std::string& name, int value);
		void SetFloat(const std::string& name, float value);

		void SetVec3(const std::string& name, glm::vec3 value);
		void SetVec4(const std::string& name, glm::vec4 value);
		void SetMat4(const std::string& name, glm::mat4 value);

		virtual void Use();

	protected:
		Shader* _shader;

		Material();


	};
}



