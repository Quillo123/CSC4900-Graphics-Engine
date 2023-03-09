#pragma once
#include "Transform.h"
#include <iostream>

namespace Graphics_Engine {

	class SceneObject
	{
	public:
		int ID;
		std::string name;

		Transform transform;


		/// <summary>
		/// Called when the object is first loaded
		/// </summary>
		virtual void Start() {}

		/// <summary>
		/// Called every frame;
		/// </summary>
		virtual void Update() {}

		virtual void Render(){}

		/// <summary>
		/// Returns a deep copy of the object
		/// </summary>
		virtual SceneObject* Copy() = 0;
	};
}