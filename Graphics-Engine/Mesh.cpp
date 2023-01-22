#include "Mesh.h"
#include <iostream>

Graphics_Engine::Mesh::Mesh(int verticesLength, vec3* vertices, int trianglesLength, int* triangles)
{
	this->SetVertices(verticesLength, vertices);
	this->SetTriangles(trianglesLength, triangles);

	uvs0Length = 0;
	uvs0 = nullptr;
}

void Graphics_Engine::Mesh::SetVertices(int length, vec3* verts)
{
	if (length < 0 || verts == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	verticesLength = length;
	vertices = new vec3[length];
	for (int i = 0; i < length; i++) {
		vertices[i] = verts[i];
	}
}

vec3 Graphics_Engine::Mesh::GetVertex(int index) 
{
	if (index >= verticesLength || index < 0) {
		std::cerr << "index out of range" << std::endl;
		return vec3(0, 0, 0);
	}
	return vertices[index];
}

int Graphics_Engine::Mesh::GetVerticesLength()
{
	return verticesLength;
}

void Graphics_Engine::Mesh::SetTriangles(int length, int* triangles)
{
	if (length <= 0 || triangles == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	trianglesLength = length;
	this->triangles = new int[length];
	for (int i = 0; i < length; i++) {
		this->triangles[i] = triangles[i];
	}
}

int Graphics_Engine::Mesh::GetTrianglesIndex(int index)
{
	if (index < 0 || index >= trianglesLength) {
		std::cerr << "index out of range" << std::endl;
		return -1;
	}
	return triangles[index];
}

int Graphics_Engine::Mesh::GetTrianglesLength()
{
	return trianglesLength;
}

void Graphics_Engine::Mesh::SetUvs0(int length, vec2* uvs)
{
	if (length < 0 || uvs == nullptr) {
		std::cerr << "Cannot input empty array; Use mesh.Clear() instead;" << std::endl;
		return;
	}

	uvs0Length = length;
	uvs0 = new vec2[length];
	for (int i = 0; i < length; i++) {
		uvs0[i] = uvs[i];
	}
}

vec2 Graphics_Engine::Mesh::GetUvs0Idex(int index)
{
	if (index < 0 || index >= uvs0Length) {
		std::cerr << "index out of range" << std::endl;
		return vec2(0,0);
	}
	return uvs0[index];
}

int Graphics_Engine::Mesh::GetUvs0Length()
{
	return uvs0Length;
}
