#ifndef MOVEABLEWALL_HPP
#define MOVEABLEWALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "../entity/entity.hpp"
#include "../physics/physicsobject.hpp"


class MoveableWall : public Entity
{
    PhysicsObject physics;
    sf::RectangleShape shape;

    public:
 
    MoveableWall(sf::Vector2f pos, sf::Vector2f size) : Entity(), shape(size),
        physics(pos, size, 0, 0.2)
    {
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(pos);
    }

    void Update() override
    {
        physics.PhysicsUpdate();
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            physics.velocity.x -= 1;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            physics.velocity.x += 1;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            physics.velocity.y -= 1;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            physics.velocity.y += 1;
    }

    void Render(Camera & camera) override
    {
        shape.setPosition(physics.position);
        camera.draw(shape);
    }

};

#endif