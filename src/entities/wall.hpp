#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

#include "../entity/entity.hpp"
#include "../physics/physicsobject.hpp"
#include "../camera/camera.hpp"


class Wall : public Entity
{
    sf::RectangleShape shape;
    PhysicsObject physics;

    public:

    Wall(sf::Vector2f pos, sf::Vector2f size) : Entity(), shape(size),
        physics(pos, size, 0, 0)
    {
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(pos);
    }



    void Update() override;

    void Render(Camera & camera) override;
    
};

#endif