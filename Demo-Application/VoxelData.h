#pragma once
#include <glm/glm.hpp>

using namespace glm;

class VoxelData
{
public:
	static vec3 Vertices[8];
	static int Triangles[8][4];
	static vec2 uvs[4];
};

vec3 VoxelData::Vertices[] = {
	vec3(0.0f, 0.0f, 0.0f),
	vec3(1.0f, 0.0f, 0.0f),
	vec3(1.0f, 1.0f, 0.0f),
	vec3(0.0f, 1.0f, 0.0f),
	vec3(0.0f, 0.0f, 1.0f),
	vec3(1.0f, 0.0f, 1.0f),
	vec3(1.0f, 1.0f, 1.0f),
	vec3(0.0f, 1.0f, 1.0f),
};

int VoxelData::Triangles[8][4] = {
	{0, 3, 1, 2}, // Back Face
	{5, 6, 4, 7}, // Front Face
	{3, 7, 2, 6}, // Top Face
	{1, 5, 0, 4}, // Bottom Face
	{4, 7, 0, 3}, // Left Face
	{1, 2, 5, 6} // Right Face
};

vec2 VoxelData::uvs[4] = {
	vec2(0,0),
	vec2(0,1),
	vec2(1,0),
	vec2(1,1)
};

