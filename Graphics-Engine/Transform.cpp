#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>
#include "Window.h"

Graphics_Engine::Transform::Transform()
{
    UpdateModel();
}

vec3 Graphics_Engine::Transform::Position()
{
    return _position;
}

void Graphics_Engine::Transform::Position(vec3 position)
{
    _position = position;
    UpdateModel();
}

void Graphics_Engine::Transform::Position(float x, float y, float z)
{
    Position(vec3(x, y, z));
}

vec3 Graphics_Engine::Transform::Rotation()
{
    return _rotation;
}

void Graphics_Engine::Transform::Rotation(vec3 rotation)
{
    _rotation = rotation;
    UpdateModel();
}

void Graphics_Engine::Transform::Rotation(float x, float y, float z)
{
    Rotation(vec3(x, y, z));
}

void Graphics_Engine::Transform::Rotate(float degrees, vec3 axis)
{
    _model = glm::rotate(_model, Window::main->GetTime() * glm::radians(degrees), axis);
}

vec3 Graphics_Engine::Transform::Scale()
{
    return _scale;
}

void Graphics_Engine::Transform::Scale(vec3 scale)
{
    _scale = scale;
    UpdateModel();
}

void Graphics_Engine::Transform::Scale(float x, float y, float z)
{
    Scale(vec3(x, y, z));
}

vec3 Graphics_Engine::Transform::Forward()
{
    return glm::normalize((vec3(inverse(_model)[2])));
}

vec3 Graphics_Engine::Transform::Up()
{
    return glm::normalize((vec3(inverse(_model)[1])));
}

vec3 Graphics_Engine::Transform::Right()
{
    return glm::normalize((vec3(inverse(_model)[0])));
}

mat4 Graphics_Engine::Transform::Model()
{
    return _model;
}

std::string Graphics_Engine::Transform::ToString()
{
    std::stringstream stream;
    stream << "Transform:" << std::endl;
    stream << "\tPostion: " << _position.x << ',' << _position.y << "," << _position.z << std::endl;
    stream << "\tRotation: " << _rotation.x << ',' << _rotation.y << ',' << _rotation.z << std::endl;
    stream << "\tScale: " << _scale.x << ',' << _scale.y << ',' << _scale.z << std::endl;
    return stream.str();
}

void Graphics_Engine::Transform::UpdateModel()
{
    _model = mat4(1.0f);

    _model = glm::translate(_model, _position);

    _model = glm::rotate(_model, _rotation.y, vec3(0, 1, 0));
    _model = glm::rotate(_model, _rotation.z, vec3(0, 0, 1));
    _model = glm::rotate(_model, _rotation.x, vec3(1, 0, 0));

    _model = glm::scale(_model, _scale);
}


