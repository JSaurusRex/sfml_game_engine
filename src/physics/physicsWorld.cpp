#include "physicsWorld.hpp"

void PhysicsWorld::AddObject(PhysicsObject * object)
{
    objects.push_back(object);
}

void PhysicsWorld::RemoveObject(PhysicsObject * object)
{
    for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i] == object)
        {
            objects.erase(objects.begin()+i);
        }
    }
}

bool PhysicsWorld::checkCollision(PhysicsObject* obj1, PhysicsObject* obj2)
{
    if(obj1->position.x > obj2->position.x+obj2->size.x)
        return false;

    if(obj2->position.x > obj1->position.x+obj1->size.x)
        return false;

    if(obj1->position.y > obj2->position.y+obj2->size.y)
        return false;

    if(obj2->position.y > obj1->position.y+obj1->size.y)
        return false;

    return true;
}


bool PhysicsWorld::checkCollisions(PhysicsObject* object, std::function<void(PhysicsObject * obj1, PhysicsObject * obj2)> func)
{
    bool collided = false;
    for(int i = 0; i < objects.size(); i++)
    {
        if(objects[i] == object)
            continue;

        bool collision = PhysicsWorld::checkCollision(object, objects[i]);

        if(collision)
        {
            func(object, objects[i]);
            collided = true;
        }   
    }
    return collided;
}