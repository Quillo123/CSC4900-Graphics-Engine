#include "Object.h"
#include <map>

#pragma once

namespace Graphics_Engine {

	class Scene
	{
	public:
		int currKey = 0;
		std::map<int, Object*> objects;

		/// <summary>
		/// Creates a copy of the given object and adds it to the scene
		/// </summary>
		/// <param name="object">The object to be instantiated</param>
		/// <param name="position">The world position at which to place the object</param>
		/// <param name="rotation">The rotation of the object</param>
		/// <param name="scale">The scale of the object</param>
		/// <returns>A pointer to the new Object</returns>
		Object* Instantiate(Object* object, vec3 position, vec3 rotation, vec3 scale);
		Object* Instantiate(Object* object, vec3 position, vec3 rotation);
		Object* Instantiate(Object* object, vec3 position);
		Object* Instantiate(Object* object);

		void Start();

		void Update();

	private:
		void AddObject(Object* object, bool override = false);

		int GetNewKey();



	};

}

