#include "Transform.h"
#include <iostream>

#pragma once

namespace Graphics_Engine {

	class Object
	{
	public:
		
		std::string name;
		Transform transform;

		/// <summary>
		/// Defines how this object is rendered. Called every frame
		/// </summary>
		virtual void Render() = 0;
		

	};
}

