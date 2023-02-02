#include "Shader.h"
#include <fstream>
#include <glad/glad.h>

using namespace Graphics_Engine;

Shader* Shader::CreateShader(std::string vertexShaderFilePath, std::string fragmentShaderFilePath)
{
	std::ifstream vertexShaderFile = std::ifstream(vertexShaderFilePath);
	if (vertexShaderFile.fail() || !vertexShaderFile.is_open()) {
		std::cerr << "Failed to open file: " << vertexShaderFilePath << std::endl;
		return nullptr;
	}

	std::string vertexShader(std::istreambuf_iterator<char>{vertexShaderFile}, {});

	std::ifstream fragmentShaderFile = std::ifstream(fragmentShaderFilePath);
	if (fragmentShaderFile.fail() || !fragmentShaderFile.is_open()) {
		std::cerr << "Failed to open file: " << fragmentShaderFilePath << std::endl;
		return nullptr;
	}

	std::string fragmentShader(std::istreambuf_iterator<char>{fragmentShaderFile}, {});



	const char* cstr_vertexShader = vertexShader.c_str();
	const char* cstr_fragmentShader = fragmentShader.c_str();

	int success;
	char infolog[512];

	unsigned int vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &(cstr_vertexShader), NULL);
	glCompileShader(vertexShaderId);
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(vertexShaderId, 512, NULL, infolog);
		std::cerr << "ERROR: Vertex Shader Compilation Failed; FILE:" << vertexShaderFilePath << std::endl << infolog << std::endl;
		return nullptr;
	}
	else {
		std::cout << vertexShaderFilePath << " Compiled Successfully;" << std::endl;
	}

	unsigned int fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &(cstr_fragmentShader), NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);


	if (!success) {
		glGetShaderInfoLog(fragmentShaderId, 512, NULL, infolog);
		std::cerr << "ERROR: Fragment Shader Compilation Failed; FILE:" << vertexShaderFilePath << std::endl << infolog << std::endl;
		return nullptr;
	}
	else {
		std::cout << fragmentShaderFilePath << " Compiled Successfully;" << std::endl;
	}

	unsigned int shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShaderId);
	glAttachShader(shaderProgram, fragmentShaderId);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infolog);
		std::cerr << "ERROR: Shader Linking Failed;" << std::endl << infolog << std::endl;
		return nullptr;
	}
	else {
		std::cout << "Shader Program Linked Successfully;" << std::endl;
	}

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);

	Shader* shader = new Shader(shaderProgram);

	return shader;
}

void Graphics_Engine::Shader::Use()
{
	glUseProgram(_shaderProgram);
}

Graphics_Engine::Shader::Shader(unsigned int shaderProgram)
{
	_shaderProgram = shaderProgram;
}
