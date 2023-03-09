#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv0;


out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    texCoord = vec2(uv0.x, uv0.y);
    gl_Position = projection * view * model  * vec4(pos, 1.0f);
}