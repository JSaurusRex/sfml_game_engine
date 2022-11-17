#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "../entity/entity.hpp"
#include "../physics/physicsobject.hpp"
#include "../camera/camera.hpp"


class Player : public Entity
{
    sf::CircleShape shape;
    PhysicsObject physics;

    int grounded;

    int bulletTimeout = 0;

    public:

    Player() : Entity(), shape(40.0f),
        physics(sf::Vector2f(0,0), sf::Vector2f(80,80), 0.5, 0.05)
    {
        shape.setFillColor(sf::Color::Green);
        grounded = -1;
    }



    void Update() override;

    void Render(Camera & camera) override;
    
};

#endif