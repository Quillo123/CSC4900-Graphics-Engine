#include "Mesh.h"
#include <iostream>

Graphics_Engine::Mesh::Mesh(int verticesLength, vec3* vertices, int trianglesLength, int* triangles)
{
	this->SetVertices(verticesLength, vertices);
	this->SetTriangles(trianglesLength, triangles);

	_uvs0Length = 0;
	_uvs0 = nullptr;
}

void Graphics_Engine::Mesh::SetVertices(int length, vec3* verts)
{
	if (length < 0 || verts == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	_verticesLength = length;
	_vertices = new vec3[length];
	for (int i = 0; i < length; i++) {
		_vertices[i] = verts[i];
	}
}

vec3 Graphics_Engine::Mesh::GetVertex(int index) 
{
	if (index >= _verticesLength || index < 0) {
		std::cerr << "index out of range" << std::endl;
		return vec3(0, 0, 0);
	}
	return _vertices[index];
}

int Graphics_Engine::Mesh::GetVerticesLength()
{
	return _verticesLength;
}

void Graphics_Engine::Mesh::SetTriangles(int length, int* triangles)
{
	if (length <= 0 || triangles == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	_trianglesLength = length;
	this->_triangles = new int[length];
	for (int i = 0; i < length; i++) {
		this->_triangles[i] = triangles[i];
	}
}

int Graphics_Engine::Mesh::GetTrianglesIndex(int index)
{
	if (index < 0 || index >= _trianglesLength) {
		std::cerr << "index out of range" << std::endl;
		return -1;
	}
	return _triangles[index];
}

int Graphics_Engine::Mesh::GetTrianglesLength()
{
	return _trianglesLength;
}

void Graphics_Engine::Mesh::SetUvs0(int length, vec2* uvs)
{
	if (length < 0 || uvs == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	_uvs0Length = length;
	_uvs0 = new vec2[length];
	for (int i = 0; i < length; i++) {
		_uvs0[i] = uvs[i];
	}
}

vec2 Graphics_Engine::Mesh::GetUvs0Idex(int index)
{
	if (index < 0 || index >= _uvs0Length) {
		std::cerr << "index out of range" << std::endl;
		return vec2(0,0);
	}
	return _uvs0[index];
}

int Graphics_Engine::Mesh::GetUvs0Length()
{
	return _uvs0Length;
}
