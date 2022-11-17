#include "physicsobject.hpp"

#include <math.h>
#include <iostream>

void PhysicsObject::PhysicsUpdate()
{
    grounded = false;
    touchingWall = false;
    colliding = false;

    velocity.x *= (1-drag);
    velocity.y *= (1-drag);

    if(!grounded)
        velocity.y += weight;

    lastPos = position;

    position.x += velocity.x;

    if(PhysicsWorld::instance().checkCollisions(this, [](PhysicsObject * obj1, PhysicsObject * obj2)
    {
        float x = obj1->position.x;
        float x2 = obj2->position.x + obj2->size.x/2;

        obj1->position.x = obj2->position.x;

        if(x > x2)
        {
            obj1->position.x += obj2->size.x + 0.01;
        }else
        {
            obj1->position.x -= obj1->size.x + 0.01;
        }
        
        obj1->velocity.x = obj1->velocity.x*(-obj1->bouncy);
        obj1->touchingWall = true;
    }))
    {
        //collision
        colliding = true;
    }
    
    position.y += velocity.y;

    PhysicsObject * obj;


    if(PhysicsWorld::instance().checkCollisions(this, [](PhysicsObject * obj1, PhysicsObject * obj2)
    {
        float y = obj1->position.y;
        float y2 = obj2->position.y + obj2->size.y/2;

        obj1->position.y = obj2->position.y;

        if(y > y2)
        {
            obj1->position.y += obj2->size.y + 0.01;
        }else
        {
            obj1->position.y -= obj1->size.y + 0.01;
            obj1->grounded = true;
        }
        
        obj1->velocity.y = obj1->velocity.y*(-obj1->bouncy);
    }))
    {
        //collision
        colliding = true;
    }
}