#include "Transform.h"
#include <iostream>

#pragma once

namespace Graphics_Engine {

	/// <summary>
	/// Base class or creating a scene object
	/// </summary>
	class Object
	{
	public:
		
		std::string name;
		Transform transform;

		/// <summary>
		/// Called when the object is first loaded
		/// </summary>
		virtual void Start() = 0; 

		/// <summary>
		/// Called every frame;
		/// Use this for rendering
		/// </summary>
		virtual void Update() = 0;
		

	};
}

