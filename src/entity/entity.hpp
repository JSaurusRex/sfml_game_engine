#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "../entityController/entitycontroller.hpp"
#include "../camera/camera.hpp"

class Entity
{

    public:

    Entity()
    {
        EntityController::instance().AddEntity(this);
    }

    ~Entity()
    {
        EntityController::instance().RemoveEntity(this);
    }

    virtual void Update() = 0;

    virtual void Render(Camera & camera) = 0; 
};

#endif