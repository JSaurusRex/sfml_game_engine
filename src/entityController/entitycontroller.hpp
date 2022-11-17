#ifndef ENTITYCONTROLLER_HPP
#define ENTITYCONTROLLER_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "../camera/camera.hpp"

class Entity;


class EntityController
{
    private:
    std::vector<Entity*> entities;
    public:

    static EntityController& instance()
    {
        static EntityController* instance = new EntityController();
        return *instance;
    }

    void AddEntity(Entity * entity);

    void RemoveEntity(Entity * entity);

    void Update();

    void Render(Camera & camera);


};

#include "../entity/entity.hpp"

#endif