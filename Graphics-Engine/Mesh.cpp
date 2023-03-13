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
	_uvs0 = nullptr;
}

Graphics_Engine::Mesh::Mesh(std::list<vec3> vertices, std::list<int> triangles)
{
	glGenVertexArrays(1, &_vertexArrayId);
	glGenBuffers(1, &_vertexBufferId);
	glGenBuffers(1, &_trianglesBufferId);

	this->SetVertices(vertices);
	this->SetTriangles(triangles);
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
	if (length < 0 || verts == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	delete[] _vertices;

	_verticesLength = length;
	_vertices = new vec3[length];
	for (int i = 0; i < length; i++) {
		_vertices[i] = verts[i];
	}

	ReloadVertices();
}

void Graphics_Engine::Mesh::SetVertices(std::list<vec3> verts)
{
	delete[] _vertices;

	_verticesLength = verts.size();
	_vertices = new vec3[_verticesLength];
	int i = 0;
	while (verts.size() > 0)
	{
		_vertices[i] = verts.front();
		verts.pop_front();
		i++;
	}
	ReloadVertices();
}

vec3 Graphics_Engine::Mesh::GetVertex(int index) 
{
	if (index >= _verticesLength || index < 0) {
		std::cerr << "index out of range" << std::endl;
		return vec3(0, 0, 0);
	}
	vec3 v = _vertices[index];
	return v;
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

	delete[] this->_triangles;

	_trianglesLength = length;
	this->_triangles = new int[length];
	for (int i = 0; i < length; i++) {
		this->_triangles[i] = triangles[i];
	}

	Use();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _trianglesLength * sizeof(int), _triangles, _drawMode);
	UnUse();
}

void Graphics_Engine::Mesh::SetTriangles(std::list<int> triangles)
{
	delete[] _triangles;

	_trianglesLength = triangles.size();
	_triangles = new int[_trianglesLength];
	
	int i = 0;
	while (triangles.size() > 0)
	{
		_triangles[i] = triangles.front();
		triangles.pop_front();
		i++;
	}

	Use();
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
	if (length <= 0 || uvs == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	if (length != _verticesLength) {
		std::cerr << "uvs length and vertices length must match" << std::endl;
		return;
	}

	delete[] _uvs0;

	_uvs0 = new vec2[length];
	for (int i = 0; i < length; i++) {
		_uvs0[i] = uvs[i];
	}
	ReloadVertices();
}

void Graphics_Engine::Mesh::SetUvs0(std::list<vec2> uvs)
{
	if (uvs.size() != _verticesLength) {
		std::cerr << "uvs length and vertices length must match" << std::endl;
		return;
	}

	delete[] _uvs0;
	_uvs0 = new vec2[uvs.size()];
	int i = 0;
	while (uvs.size() > 0)
	{
		_uvs0[i] = uvs.front();
		uvs.pop_front();
		i++;
	}
	ReloadVertices();
}

vec2 Graphics_Engine::Mesh::GetUvs0Index(int index)
{
	if (index < 0 || index >= _verticesLength) {
		std::cerr << "index out of range" << std::endl;
		return vec2(0,0);
	}
	return _uvs0[index];
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

	// Position Attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// UV0 Attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
}

void Graphics_Engine::Mesh::UnUse()
{
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Graphics_Engine::Mesh::ReloadVertices()
{
	float* vertices = new float[_verticesLength * 5];

	int j = 0;
	for (int i = 0; i < _verticesLength * 5; i+=5) {
		
		vertices[i] = _vertices[j].x;
		vertices[i + 1] = _vertices[j].y;
		vertices[i+2] = _vertices[j].z;

		if (_uvs0 == nullptr) {
			vertices[i + 3] = 0;
			vertices[i + 4] = 0;
		}
		else {
			vertices[i+3] = _uvs0[j].x;
			vertices[i+4] = _uvs0[j].y;
		}
		j++;
	}

	Use();
	glBufferData(GL_ARRAY_BUFFER, _verticesLength * sizeof(float) * 5, vertices, _drawMode);
	UnUse();

}

