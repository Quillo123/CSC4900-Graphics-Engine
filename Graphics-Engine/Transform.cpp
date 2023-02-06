#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <sstream>

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

vec3 Graphics_Engine::Transform::GetRotation()
{
    return _rotation;
}

void Graphics_Engine::Transform::SetRotation(vec3 rotation)
{
    _rotation = rotation;
    UpdateModel();
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

    _model = glm::rotate(_model, _rotation.x, vec3(1, 0, 0));
    _model = glm::rotate(_model, _rotation.y, vec3(0, 1, 0));
    _model = glm::rotate(_model, _rotation.z, vec3(0, 0, 1));

    _model = glm::translate(_model, _position);   
    _model = glm::scale(_model, _scale);
}


