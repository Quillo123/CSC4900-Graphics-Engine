#pragma once 
#include <map>
#include "Camera.h"
#include <list>


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
		/// <summary>
		/// Creates a copy of the given object and adds it to the scene
		/// </summary>
		/// <param name="object">The object to be instantiated</param>
		/// <param name="position">The world position at which to place the object</param>
		/// <param name="rotation">The rotation of the object</param>
		/// <returns>A pointer to the new Object</returns>
		SceneObject* Instantiate(SceneObject* object, vec3 position, vec3 rotation);
		/// <summary>
		/// Creates a copy of the given object and adds it to the scene
		/// </summary>
		/// <param name="object">The object to be instantiated</param>
		/// <param name="position">The world position at which to place the object</param>
		/// <returns>A pointer to the new Object</returns>
		SceneObject* Instantiate(SceneObject* object, vec3 position);
		/// <summary>
		/// Creates a copy of the given object and adds it to the scene
		/// </summary>
		/// <param name="object">The object to be instantiated</param>
		/// <returns>A pointer to the new Object</returns>
		SceneObject* Instantiate(SceneObject* object);

		/// <summary>
		/// Returns the first object with the given name
		/// </summary>
		SceneObject* FindObject(std::string name);

		/// <summary>
		/// Returns a list of all objects with the given name
		/// </summary>
		std::list<SceneObject*> FindObjects(std::string name);

		/// <summary>
		/// Call's Start on every object in the scene
		/// </summary>
		void Start();

		/// <summary>
		/// Call's Update on every object in the scene
		/// </summary>
		void Update();

		/// <summary>
		/// Call's Render on every object in the scene
		/// </summary>
		void Render();

	private:
		void AddObject(SceneObject* object, bool override = false);

		int GetNewKey();
	};

}

