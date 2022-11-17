#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <functional>

class PhysicsObject;

class PhysicsWorld
{
    private:
    std::vector<PhysicsObject*> objects;

    public:

    static PhysicsWorld& instance()
    {
        static PhysicsWorld* instance = new PhysicsWorld();
        return *instance;
    }

    void AddObject(PhysicsObject * object);

    void RemoveObject(PhysicsObject * object);


    static bool checkCollision(PhysicsObject* obj1, PhysicsObject* obj2);
    
    bool checkCollisions(PhysicsObject* object, std::function<void(PhysicsObject * obj1, PhysicsObject * obj2)> func);


    PhysicsObject * operator[] (int index)
    {
        return objects[index];
    }

};

#include "physicsobject.hpp"

#endif