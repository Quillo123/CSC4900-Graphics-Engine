#include "Object.h"
#include "Mesh.h"
#include "Shader.h"
#include <glm/glm.hpp>

#pragma once

namespace Graphics_Engine {

	class MeshRenderer : public Object
	{
	public:


		MeshRenderer(Shader* shader);

		MeshRenderer(Shader* shader, Mesh* mesh);

		MeshRenderer(Shader* shader, vec3 vertices[], int vertexCount, int triangles[], int triangleCount);

		~MeshRenderer();

		void Start() override;

		void Update() override;

		Object* Copy() override;
		
	private:
		Mesh* _mesh;
		Shader* _shader;

	};

}

