#include "Scene.h"
#include "Object.h"
#include <map>


using namespace Graphics_Engine;

Object* Graphics_Engine::Scene::Instantiate(Object* object, vec3 position, vec3 rotation, vec3 scale)
{
    auto obj = Instantiate(object, position, rotation);
    obj->transform.SetScale(scale);
    return obj;
}    


Object* Graphics_Engine::Scene::Instantiate(Object* object, vec3 position, vec3 rotation)
{
    auto obj = Instantiate(object, position);
    obj->transform.SetRotation(rotation);
    return obj;
}

Object* Graphics_Engine::Scene::Instantiate(Object* object, vec3 position)
{
    auto obj = Instantiate(object);
    obj->transform.SetPosition(position);
    return obj;
}

Object* Graphics_Engine::Scene::Instantiate(Object* object)
{
    Object* obj = object->Copy();
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

void Graphics_Engine::Scene::AddObject(Object* object, bool override)
{
    if (override) {
        if (objects.at(object->ID) == nullptr) {
            objects.erase(object->ID);
        }
        objects.insert(std::pair<int, Object*>{ object->ID, object });
    }
    else {
        int key = GetNewKey();
        object->ID = key;

        objects.insert(std::pair<int, Object*>{ key, object });

    }
}

int Graphics_Engine::Scene::GetNewKey()
{
    int key = currKey;
    currKey++;
    return key;
}
