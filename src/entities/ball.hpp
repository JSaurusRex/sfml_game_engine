#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "../entity/entity.hpp"
#include "../physics/physicsobject.hpp"


class Ball : public Entity
{
    PhysicsObject physics;
    sf::CircleShape shape;

    public:

    Ball(sf::Vector2f position, sf::Vector2f velocity) : physics(position, sf::Vector2f(40,40), 0, 0, 1), shape(20)
    {
        shape.setFillColor(sf::Color::Green);
        physics.velocity = velocity;
    }

    void Update() override
    {
        physics.PhysicsUpdate();
    }

    void Render(Camera & camera) override
    {
        shape.setPosition(physics.position);
        camera.draw(shape);
    }

};

#endif