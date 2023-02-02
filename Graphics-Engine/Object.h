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
		/// <summary>
		/// DO NOT MODIFY
		/// </summary>
		int ID;
		std::string name;
		Transform transform;

		/// <summary>
		/// Called when the object is first loaded
		/// </summary>
		virtual void Start() = 0; 

		/// <summary>
		/// Called every frame;
		/// </summary>
		virtual void Update() = 0;
		
		/// <summary>
		/// Returns a deep copy of the object
		/// </summary>
		virtual Object* Copy() = 0;
	};
}

