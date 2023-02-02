#include <iostream>

#pragma once

namespace Graphics_Engine {


	class Shader
	{
	public:
		static Shader* CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath);

		void Use();



	private:

		unsigned int _shaderProgram;

		Shader();
		Shader(unsigned int shaderProgram);

	};

}
