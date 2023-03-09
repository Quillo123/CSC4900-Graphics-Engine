#include <iostream>
#include <glm/glm.hpp>


#pragma once

namespace Graphics_Engine {


	class Shader
	{
	public:		
		static Shader* CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);

		void Use();


		void SetBool(const std::string& name, bool value);
		void SetInt(const std::string& name, int value);
		void SetFloat(const std::string& name, float value);
		
		void SetVec3(const std::string& name, glm::vec3 value);
		void SetVec4(const std::string& name, glm::vec4 value);
		void SetMat4(const std::string& name, glm::mat4 value);

	private:

		unsigned int _shaderProgramID;

		Shader();
		Shader(unsigned int shaderProgram);

	};

}
