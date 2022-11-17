#ifndef PHYSICSOBJECT_HPP
#define PHYSICSOBJECT_HPP

#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>

#include "physicsWorld.hpp"

class PhysicsObject
{
    public:
    sf::Vector2f position;
    sf::Vector2f lastPos;
    sf::Vector2f velocity;
    sf::Vector2f size;

    float weight;
    float drag;
    float bouncy;

    bool grounded;
    bool touchingWall;
    bool colliding;

    PhysicsObject(sf::Vector2f position, sf::Vector2f size, float weight=0, float drag=0, float bouncy=0) :
                    position(position), velocity(0,0), size(size), weight(weight), drag(drag), bouncy(bouncy),grounded(false), touchingWall(false)
    {
        PhysicsWorld::instance().AddObject(this);
    }

    ~PhysicsObject()
    {
        PhysicsWorld::instance().RemoveObject(this);
    }

    void PhysicsUpdate();

};

#endif