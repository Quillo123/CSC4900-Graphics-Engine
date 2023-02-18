#include "Scene.h"
#include "SceneObject.h"
#include <map>
#include <list>
#include <string>


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

    SceneObject* test = FindObject(object->name);
    int nameModifier = 0;
    while(test != nullptr)
    {
        nameModifier++;
        test = FindObject(test->name + std::to_string(nameModifier));
    }

    

    SceneObject* obj = object->Copy();

    if (nameModifier != 0) {
        obj->name = object->name + std::to_string(nameModifier);
    }

    //obj->scene = this;
    AddObject(obj, false);
    return obj;
}

SceneObject* Graphics_Engine::Scene::FindObject(std::string name)
{
    for (auto const& [key, val] : objects)
    {
        if (val->name == name) {
            return val;
        }
    }
    return nullptr;
}

std::list<SceneObject*> Graphics_Engine::Scene::FindObjects(std::string name)
{
    std::list<SceneObject*> objs = std::list<SceneObject*>();
    
    for (auto const& [key, val] : objects)
    {
        if (val->name == name) {
            objs.push_back(val);
        }
    }

    return objs;
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
