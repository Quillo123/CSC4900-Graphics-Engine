#include "Scene.h"
#include "SceneObject.h"
#include <map>


using namespace Graphics_Engine;

SceneObject* Graphics_Engine::Scene::Instantiate(SceneObject* object, vec3 position, vec3 rotation, vec3 scale)
{
    auto obj = Instantiate(object, position, rotation);
    obj->transform.SetScale(scale);
    return obj;
}    


SceneObject* Graphics_Engine::Scene::Instantiate(SceneObject* object, vec3 position, vec3 rotation)
{
    auto obj = Instantiate(object, position);
    obj->transform.SetRotation(rotation);
    return obj;
}

SceneObject* Graphics_Engine::Scene::Instantiate(SceneObject* object, vec3 position)
{
    auto obj = Instantiate(object);
    obj->transform.SetPosition(position);
    return obj;
}

SceneObject* Graphics_Engine::Scene::Instantiate(SceneObject* object)
{
    SceneObject* obj = object->Copy();
    //obj->scene = this;
    AddObject(obj, false);
    return obj;
}

void Graphics_Engine::Scene::Start()
{
    for (auto const& [key, val] : objects)
    {
        val->Start();
    }
}

void Graphics_Engine::Scene::Update()
{
    for (auto const& [key, val] : objects)
    {
        val->Update();
    }
}

void Graphics_Engine::Scene::AddObject(SceneObject* object, bool override)
{
    if (override) {
        if (objects.at(object->ID) == nullptr) {
            objects.erase(object->ID);
        }
        objects.insert(std::pair<int, SceneObject*>{ object->ID, object });
    }
    else {
        int key = GetNewKey();
        object->ID = key;

        objects.insert(std::pair<int, SceneObject*>{ key, object });

    }
}

int Graphics_Engine::Scene::GetNewKey()
{
    int key = currKey;
    currKey++;
    return key;
}
