#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "../entity/entity.hpp"
#include "../physics/physicsobject.hpp"


class Bullet : public Entity
{
    PhysicsObject physics;
    sf::CircleShape shape;

    int time;

    public:

    Bullet(sf::Vector2f position, sf::Vector2f velocity) : 
        Entity(), physics(position, sf::Vector2f(20,20), 0, 0), shape(10), time(0)
    {
        shape.setFillColor(sf::Color::Black);
        physics.velocity = velocity;
    }

    void Update() override
    {
        if(physics.velocity.x == 0 || time > 60)
        {
            delete this;
        }
        physics.PhysicsUpdate();
        time++;
    }

    void Render(Camera & camera) override
    {
        shape.setPosition(physics.position);
        camera.draw(shape);
    }

};

#endif