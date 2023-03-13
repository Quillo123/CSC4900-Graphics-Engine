#pragma once
#include <glm/glm.hpp>

using namespace glm;

class VoxelData
{
public:
	static vec3 Vertices[8];
	static int Triangles[8][4];
	static vec2 uvs[4];
	static ivec3 faceChecks[6];
};

