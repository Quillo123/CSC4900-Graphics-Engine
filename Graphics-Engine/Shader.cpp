#include "Shader.h"
#include <fstream>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>

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
	glUseProgram(_shaderProgramID);
}

void Graphics_Engine::Shader::SetBool(const std::string& name, bool value)
{
	glUniform1i(glGetUniformLocation(_shaderProgramID, name.c_str()), (int)value);
}

void Graphics_Engine::Shader::SetInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(_shaderProgramID, name.c_str()), value);
}

void Graphics_Engine::Shader::SetFloat(const std::string& name, float value)
{
	glUniform1f(glGetUniformLocation(_shaderProgramID, name.c_str()), value);
}

void Graphics_Engine::Shader::SetVec3(const std::string& name, glm::vec3 value)
{
	glUniform3fv(glGetUniformLocation(_shaderProgramID, name.c_str()), 1, glm::value_ptr(value));
}

void Graphics_Engine::Shader::SetVec4(const std::string& name, glm::vec4 value)
{
	glUniform4fv(glGetUniformLocation(_shaderProgramID, name.c_str()), 1, glm::value_ptr(value));
}

void Graphics_Engine::Shader::SetMat4(const std::string& name, glm::mat4 value)
{
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgramID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

Graphics_Engine::Shader::Shader(unsigned int shaderProgram)
{
	_shaderProgramID = shaderProgram;
}
