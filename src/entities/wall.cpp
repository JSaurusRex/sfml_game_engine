#include "wall.hpp"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>

void Wall::Update()
{
}

void Wall::Render(Camera & camera)
{
    shape.setPosition(physics.position);
    camera.draw(shape);
}