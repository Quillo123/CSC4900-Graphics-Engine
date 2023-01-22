#include <glm/glm.hpp>

using namespace glm;

#pragma once

namespace Graphics_Engine {

	class Mesh
	{
	public:


		Mesh(int verticesLength, vec3* vertices, int trianglesLength, int* triangles);

		void SetVertices(int length, vec3* verts);
		vec3 GetVertex(int index);
		int GetVerticesLength();

		void SetTriangles(int length, int* triangles);
		int GetTrianglesIndex(int index);
		int GetTrianglesLength();

		void SetUvs0(int length, vec2* uvs);
		vec2 GetUvs0Idex(int index);
		int GetUvs0Length();

	private:
		int verticesLength;
		vec3* vertices;

		int trianglesLength;
		int* triangles;

		int uvs0Length;
		vec2* uvs0;
	};
}



