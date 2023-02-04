#include "Material.h"
#include "Texture.h"



#pragma once

namespace Graphics_Engine {

	class MeshMaterial : public Material
	{
	public:
		MeshMaterial(Shader* shader);
		MeshMaterial(Shader* shader, Texture tex);

		void Use() override;

		Texture texture;


	};
}

