#include "Chunk.h"
#include <list>
#include "VoxelData.h"

using namespace std;

const int Chunk::width = 32, Chunk::height = 32, Chunk::length = 32;

Chunk::Chunk(Material* material) : MeshRenderer(material) {
	blocks = new Block[width * height * length];
}

Chunk::~Chunk() {
	delete[] blocks;
}

Block Chunk::GetBlock(int x, int y, int z) {
	return blocks[Index(x, y, z)];
}

void Chunk::SetBlock(int x, int y, int z, Block block) {
	blocks[Index(x, y, z)] = block;
}

int Chunk::Index(int x, int y, int z) {
	return x + y * height + z * length;
}

void Chunk::ReloadMesh()
{

	list<vec3> vertices = list<vec3>();
	list<int> triangles = list<int>();
	list<vec2> uvs = list<vec2>();

	int index = 0;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int z = 0; z < length; z++)
			{
				if (GetBlock(x,y,z).solid == false)
				{
					continue;
				}
				///
				/// 
				/// Help from https://github.com/b3agz/Code-A-Game-Like-Minecraft-In-Unity/blob/master/01-the-first-voxel/Assets/Scripts/Chunk.cs
				for (int i = 0; i < 6; i++)
				{
					auto pos = vec3(x, y, z);
					if (!CheckVoxel(ivec3(x, y, z) + VoxelData::faceChecks[i]))
					{
						//Vector2 UVOffsett = BlockManager.Main.GetBlockUVOffset(blockID, i);

						vertices.push_back(pos + VoxelData::Vertices[VoxelData::Triangles[i][0]]);
						vertices.push_back(pos + VoxelData::Vertices[VoxelData::Triangles[i][1]]);
						vertices.push_back(pos + VoxelData::Vertices[VoxelData::Triangles[i][2]]);
						vertices.push_back(pos + VoxelData::Vertices[VoxelData::Triangles[i][3]]);
						uvs.push_back((VoxelData::uvs[0]));
						uvs.push_back((VoxelData::uvs[1]));
						uvs.push_back((VoxelData::uvs[2]));
						uvs.push_back((VoxelData::uvs[3]));
						triangles.push_back(index);
						triangles.push_back(index + 1);
						triangles.push_back(index + 2);
						triangles.push_back(index + 2);
						triangles.push_back(index + 1);
						triangles.push_back(index + 3);
						index += 4;
					}
				}
			}
		}
	}

	Mesh* mesh = new Mesh(vertices, triangles);
	mesh->SetUvs0(uvs);

	SetMesh(mesh);
}

bool Chunk::CheckVoxel(ivec3 position)
{
	int x = position.x;
	int y = position.y;
	int z = position.z;

	if (x < 0 || x > width - 1 || y < 0 || y > height - 1 || z < 0 || z > length - 1)
		return false;

	if (GetBlock(x,y,z).solid)
	{
		return true;
	}
	else
	{
		return false;
	}

}
