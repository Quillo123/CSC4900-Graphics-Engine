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

vec3 Graphics_Engine::Transform::GetPosition()
{
    return _position;
}

void Graphics_Engine::Transform::SetPosition(vec3 position)
{
    _position = position;
    UpdateModel();
}

void Graphics_Engine::Transform::SetPosition(float x, float y, float z)
{
    SetPosition(vec3(x, y, z));
}

vec3 Graphics_Engine::Transform::GetRotation()
{
    return _rotation;
}

void Graphics_Engine::Transform::SetRotation(vec3 rotation)
{
    _rotation = rotation;
    UpdateModel();
}

void Graphics_Engine::Transform::SetRotation(float x, float y, float z)
{
    SetRotation(vec3(x, y, z));
}

void Graphics_Engine::Transform::Rotate(float degrees, vec3 axis)
{
    _model = glm::rotate(_model, Window::main->GetTime() * glm::radians(degrees), axis);
}

vec3 Graphics_Engine::Transform::GetScale()
{
    return _scale;
}

void Graphics_Engine::Transform::SetScale(vec3 scale)
{
    _scale = scale;
    UpdateModel();
}

void Graphics_Engine::Transform::SetScale(float x, float y, float z)
{
    SetScale(vec3(x, y, z));
}

vec3 Graphics_Engine::Transform::Forward()
{
    return glm::normalize((vec3(inverse(_model)[2])));
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


    _model = glm::rotate(_model, _rotation.z, vec3(0, 0, 1));
    _model = glm::rotate(_model, _rotation.y, vec3(0, 1, 0));
    _model = glm::rotate(_model, _rotation.x, vec3(1, 0, 0));

    _model = glm::scale(_model, _scale);
}


