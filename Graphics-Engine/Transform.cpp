#include "Transform.h"

vec3 Graphics_Engine::Transform::GetPosition()
{
    return _position;
}

void Graphics_Engine::Transform::SetPosition(vec3 position)
{
    _position = position;
}

vec3 Graphics_Engine::Transform::GetRotation()
{
    return _rotation;
}

void Graphics_Engine::Transform::SetRotation(vec3 rotation)
{
    _rotation = rotation;
}

vec3 Graphics_Engine::Transform::GetScale()
{
    return _scale;
}

void Graphics_Engine::Transform::SetScale(vec3 scale)
{
    _scale = scale;
}
