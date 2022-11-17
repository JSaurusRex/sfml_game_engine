#include "entitycontroller.hpp"

#include <iostream>

void EntityController::AddEntity(Entity * entity)
{
    std::cout << "Add entity: " << entities.size() << std::endl;
    entities.push_back(entity);
}

void EntityController::RemoveEntity(Entity * entity)
{
    for(int i = 0; i < entities.size(); i++)
    {
        if(entities[i] == entity)
        {
            std::cout << "removed entity: " << i << std::endl;
            entities.erase(entities.begin()+i);
            i--;
        }
    }
}

void EntityController::Update()
{
    for(int i = 0; i < entities.size(); i++)
    {
        entities[i]->Update();
    }
}

void EntityController::Render(Camera & camera)
{
    for(int i = 0; i < entities.size(); i++)
    {
        entities[i]->Render(camera);
    }
}