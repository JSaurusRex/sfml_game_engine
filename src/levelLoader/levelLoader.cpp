#include "levelLoader.hpp"

#include <iostream>

#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <SFML/System/Vector2.hpp>

#include "../entityController/entitycontroller.hpp"
#include "../entity/entity.hpp"

#include "../entities/wall.hpp"
#include "../entities/moveableWall.hpp"
#include "../entities/ball.hpp"

bool LevelLoader::Load(std::string file)
{
    std::fstream f(file);
    json data = json::parse(f);

    int size = data["layers"][0]["objects"].size();
    for(int i = 0; i < size; i++)
    {
        json * jobj = &data["layers"][0]["objects"][i];

        std::string sClass = (*jobj)["class"];

        std::cout << sClass << std::endl;

        if(sClass == "Ball")
        {
            new Ball(sf::Vector2f((*jobj)["x"], (*jobj)["y"]), sf::Vector2f(5, 5));
        }else if(sClass == "Wall")
        {
            new Wall(sf::Vector2f((*jobj)["x"], (*jobj)["y"]), sf::Vector2f((*jobj)["width"], (*jobj)["height"]));
        }else if(sClass == "MoveableWall")
        {
            new MoveableWall(sf::Vector2f((*jobj)["x"], (*jobj)["y"]), sf::Vector2f((*jobj)["width"], (*jobj)["height"]));
        }
    }
    return false;
}