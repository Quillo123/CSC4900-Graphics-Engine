#include "Transform.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

void Graphics_Engine::Transform::UpdateModel()
{
    _model = mat4(1.0f);
    _model = glm::translate(_model, _position);
    _model = glm::rotate(_model, 1.0f, _rotation);
    _model = glm::scale(_model, _scale);
}


