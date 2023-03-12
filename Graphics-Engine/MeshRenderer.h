#pragma once
#include "SceneObject.h"
#include "Mesh.h"
#include <glm/glm.hpp>
#include "Material.h"


namespace Graphics_Engine {

	class MeshRenderer : public SceneObject
	{
	public:


		MeshRenderer(Material* material);

		MeshRenderer(Material* material, Mesh* mesh);

		MeshRenderer(Material* material, vec3 vertices[], int vertexCount, int triangles[], int triangleCount);

		~MeshRenderer();

		void Start() override;

		void Render() override;

		void Update() override;

		SceneObject* Copy() override;
		
	private:
		Mesh* _mesh;
		Material* _material;

	};

}

