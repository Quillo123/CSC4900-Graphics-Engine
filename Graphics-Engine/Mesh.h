#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h>
#include <list>

using namespace glm;


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
		Mesh(std::list<vec3> vertices, std::list<int> triangles);
		~Mesh();

		void SetVertices(int length, vec3 verts[]);
		void SetVertices(std::list<vec3> verts);
		vec3 GetVertex(int index);
		int GetVerticesLength();

		void SetTriangles(int length, int* triangles);
		void SetTriangles(std::list<int> triangles);
		int GetTrianglesIndex(int index);
		int GetTrianglesLength();

		void SetUvs0(int length, vec2* uvs);
		void SetUvs0(std::list<vec2> uvs);
		vec2 GetUvs0Index(int index);

		void SetVertextBufferMode(GLenum drawMode);

		void SetUsing();
		void SetNotUsing();
		bool IsInUse();

		void Use();
		void UnUse();

	private:
		int _verticesLength;
		vec3* _vertices;
		vec2* _uvs0;

		int _trianglesLength;
		int* _triangles;


		GLenum _drawMode = GL_STATIC_DRAW;
	
		unsigned int _vertexBufferId;
		unsigned int _trianglesBufferId;
		unsigned int _vertexArrayId;

		int _inUse;

		void ReloadVertices();
	};
}



