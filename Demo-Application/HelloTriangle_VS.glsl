#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv0;


out vec2 texCoord;

void main()
{
    texCoord = uv0;
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);
}