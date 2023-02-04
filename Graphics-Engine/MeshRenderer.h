#include "Object.h"
#include "Mesh.h"
#include <glm/glm.hpp>
#include "Material.h"

#pragma once

namespace Graphics_Engine {

	class MeshRenderer : public Object
	{
	public:


		MeshRenderer(Material* shader);

		MeshRenderer(Material* shader, Mesh* mesh);

		MeshRenderer(Material* shader, vec3 vertices[], int vertexCount, int triangles[], int triangleCount);

		~MeshRenderer();

		void Start() override;

		void Update() override;

		Object* Copy() override;
		
	private:
		Mesh* _mesh;
		Material* _material;

	};

}

