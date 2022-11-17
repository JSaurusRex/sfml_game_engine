#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Camera
{
    private:

    sf::RenderWindow & window;

    public:

    sf::Vector2f position;
    sf::Vector2f wantedPosition;
    float size;

    Camera(sf::RenderWindow & window, sf::Vector2f position, float size) :
        window(window), position(position), wantedPosition(position), size(size)
    { }

    void draw(sf::Shape & shape)  //todo add scaling / zoom  
    {
        sf::Vector2f oldPos = shape.getPosition();
        sf::Vector2f pos = oldPos;

        pos.x -= position.x;
        pos.y -= position.y;

        pos.x *= size;
        pos.y *= size;

        sf::Vector2f oldScale = shape.getScale();
        sf::Vector2f scale = oldScale;

        scale.x *= size;
        scale.y *= size;

        shape.setPosition(pos);
        shape.setScale(scale);
        window.draw(shape);
        shape.setPosition(oldPos);
        shape.setScale(oldScale);
    }

    void Update()
    {
        position.x = (position.x*5 + wantedPosition.x) / 6;
        position.y = (position.y*5 + wantedPosition.y) / 6;
    }

    void SetPosition(sf::Vector2f vec)
    {
        vec.x -= 400;
        vec.y -= 300;
        wantedPosition = vec;
    }
    
};

#endif