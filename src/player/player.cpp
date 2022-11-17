#include "player.hpp"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

#include "../entities/bullet.hpp"

void Player::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        physics.velocity.x -= 1;

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        physics.velocity.x += 1;

    else if(grounded > 0)
    {
        physics.velocity.x *= 0.9;
    }

    bulletTimeout--;

    if(bulletTimeout < 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sf::Vector2f vec = physics.position;
        vec.x += physics.size.x;
        if(physics.velocity.x > 0)
            vec.x += physics.velocity.x;
        vec.y += physics.size.y/2;
        new Bullet(vec, sf::Vector2f(30,0));
        bulletTimeout = 20;
    }

    if(grounded > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        physics.velocity.y = -20;
        grounded = 0;
    }

    if(grounded <= 0 && physics.velocity.y > 0)
    {
        physics.velocity.y += physics.weight;
        grounded = 0;
    }
    
    physics.PhysicsUpdate();


    grounded--;

    if(physics.grounded)
        grounded = 10;


    if(physics.position.y > 1200)
    {
        physics.position = sf::Vector2f(0,0);
    }
}

void Player::Render(Camera & camera)
{
    shape.setPosition(physics.position);
    // std::cout << physics.position.x << ", " << physics.position.y << std::endl;
    camera.draw(shape);

    sf::Vector2f vec = physics.position;
    vec.x += physics.size.x/2;
    vec.y += physics.size.y/2;
    camera.SetPosition(vec);
}