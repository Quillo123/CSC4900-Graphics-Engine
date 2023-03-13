#pragma once
#include <glm/glm.hpp>
#include <MeshRenderer.h>

using namespace glm;
using namespace Graphics_Engine;

struct Block {
public:
	bool solid;
	int textureID;
	ivec3 position;

	Block(bool solid = false, int textureID = 0, ivec3 position = ivec3(0,0,0)) {
		this->solid = solid;
		this->textureID = textureID;
		this->position = position;
	}
};

class Chunk : public MeshRenderer
{
public:
	static const int width, height, length;

	Block* blocks;

	Chunk(Material* material);

	~Chunk();

	Block GetBlock(int x, int y, int z);

	void SetBlock(int x, int y, int z, Block block);

	int Index(int x, int y, int z);

	void ReloadMesh();

	bool CheckVoxel(ivec3 position);
};

