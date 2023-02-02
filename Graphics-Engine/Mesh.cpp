#include "Mesh.h"
#include <glad/glad.h>
#include <iostream>

Graphics_Engine::Mesh::Mesh(int verticesLength, vec3 vertices[], int trianglesLength, int triangles[])
{
	glGenVertexArrays(1, &_vertexArrayId);
	glGenBuffers(1, &_vertexBufferId);
	glGenBuffers(1, &_trianglesBufferId);
	
	this->SetVertices(verticesLength, vertices);
	this->SetTriangles(trianglesLength, triangles);

	_uvs0Length = 0;
	_uvs0 = nullptr;

}

Graphics_Engine::Mesh::~Mesh()
{
	delete[] _vertices;
	delete[] _triangles;
	delete[] _uvs0;

	glDeleteVertexArrays(1, &_vertexArrayId);
	glDeleteBuffers(1, &_vertexBufferId);
	glDeleteBuffers(1, &_trianglesBufferId);

}

void Graphics_Engine::Mesh::SetVertices(int length, vec3 verts[])
{
	Use();
	if (length < 0 || verts == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	_verticesLength = length;
	_vertices = new float[length * 3];
	int j = 0;
	for (int i = 0; i < length; i++) {
		_vertices[j] = verts[i].x;
		_vertices[j + 1] = verts[i].y;
		_vertices[j + 2] = verts[i].z;
		j += 3;
	}

	glBufferData(GL_ARRAY_BUFFER, _verticesLength * sizeof(float) * 3, _vertices, _drawMode);
	UnUse();
}

vec3 Graphics_Engine::Mesh::GetVertex(int index) 
{
	if (index >= _verticesLength || index < 0) {
		std::cerr << "index out of range" << std::endl;
		return vec3(0, 0, 0);
	}
	int i = index * 3;
	vec3 v = vec3(_vertices[i], _vertices[i + 1], _vertices[i + 2]);
	return v;
}

int Graphics_Engine::Mesh::GetVerticesLength()
{
	return _verticesLength;
}

void Graphics_Engine::Mesh::SetTriangles(int length, int* triangles)
{
	Use();
	if (length <= 0 || triangles == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	_trianglesLength = length;
	this->_triangles = new int[length];
	for (int i = 0; i < length; i++) {
		this->_triangles[i] = triangles[i];
	}

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _trianglesLength * sizeof(int), _triangles, _drawMode);
	UnUse();
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
	Use();
	if (length < 0 || uvs == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	_uvs0Length = length;
	_uvs0 = new vec2[length];
	for (int i = 0; i < length; i++) {
		_uvs0[i] = uvs[i];
	}
	UnUse();
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

void Graphics_Engine::Mesh::SetVertextBufferMode(GLenum drawMode)
{
	if (drawMode != GL_STATIC_DRAW &&
		drawMode != GL_DYNAMIC_DRAW &&
		drawMode != GL_STREAM_DRAW) {
		std::cerr << "Invalid draw mode" << std::endl;
	}

	_drawMode = drawMode;
}

void Graphics_Engine::Mesh::SetUsing()
{
	_inUse++;
}

void Graphics_Engine::Mesh::SetNotUsing()
{
	_inUse--;
}

bool Graphics_Engine::Mesh::IsInUse()
{
	if (_inUse > 0) {
		return true;
	}
	return false;
}

void Graphics_Engine::Mesh::Use()
{
	glBindVertexArray(_vertexArrayId);
	glBindBuffer(GL_ARRAY_BUFFER, _vertexBufferId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _trianglesBufferId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Graphics_Engine::Mesh::UnUse()
{
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

