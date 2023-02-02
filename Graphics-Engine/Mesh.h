#include <glm/glm.hpp>
#include <glad/glad.h>

using namespace glm;

#pragma once

namespace Graphics_Engine {
	/// <summary>
	/// A class to manage meshes. 
	/// <para>
	/// Meshes are automatically stored in GPU memory, so only create one when needed. 
	/// </para>
	/// </summary>
	class Mesh
	{
	public:


		Mesh(int verticesLength, vec3 vertices[], int trianglesLength, int triangles[]);
		~Mesh();

		void SetVertices(int length, vec3 verts[]);
		vec3 GetVertex(int index);
		int GetVerticesLength();

		void SetTriangles(int length, int* triangles);
		int GetTrianglesIndex(int index);
		int GetTrianglesLength();

		void SetUvs0(int length, vec2* uvs);
		vec2 GetUvs0Idex(int index);
		int GetUvs0Length();

		void SetVertextBufferMode(GLenum drawMode);

		void SetUsing();
		void SetNotUsing();
		bool IsInUse();

		void Use();
		void UnUse();

	private:
		int _verticesLength;
		float* _vertices;

		int _trianglesLength;
		int* _triangles;

		int _uvs0Length;
		vec2* _uvs0;

		GLenum _drawMode = GL_STATIC_DRAW;
	
		unsigned int _vertexBufferId;
		unsigned int _trianglesBufferId;
		unsigned int _vertexArrayId;

		int _inUse;
	};
}



