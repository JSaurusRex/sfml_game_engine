#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#include "player/player.hpp"
#include "entityController/entitycontroller.hpp"
#include "physics/physicsobject.hpp"
#include "entities/wall.hpp"
#include "levelLoader/levelLoader.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "platformer");


    window.setFramerateLimit(60);

    // Player player;

    Camera camera(window, sf::Vector2f(-100,-100), 0.7);

    sf::RectangleShape background(sf::Vector2f(800, 600));

    background.setFillColor(sf::Color(170, 170, 255));

    LevelLoader::Load("Data/levels/test.tmj");





    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        camera.Update();

        EntityController::instance().Update();

        window.clear();
        window.draw(background);

        EntityController::instance().Render(camera);

        window.display();
    }

    return 0;
}