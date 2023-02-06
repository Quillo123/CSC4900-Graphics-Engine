#pragma once 
#include <map>
#include "Camera.h"

namespace Graphics_Engine {

	class Scene
	{
	public:
		int currKey = 0;
		std::map<int, SceneObject*> objects;

		Camera* mainCam = nullptr;

		/// <summary>
		/// Creates a copy of the given object and adds it to the scene
		/// </summary>
		/// <param name="object">The object to be instantiated</param>
		/// <param name="position">The world position at which to place the object</param>
		/// <param name="rotation">The rotation of the object</param>
		/// <param name="scale">The scale of the object</param>
		/// <returns>A pointer to the new Object</returns>
		SceneObject* Instantiate(SceneObject* object, vec3 position, vec3 rotation, vec3 scale);
		SceneObject* Instantiate(SceneObject* object, vec3 position, vec3 rotation);
		SceneObject* Instantiate(SceneObject* object, vec3 position);
		SceneObject* Instantiate(SceneObject* object);

		void Start();

		void Update();

	private:
		void AddObject(SceneObject* object, bool override = false);

		int GetNewKey();


	};

}

