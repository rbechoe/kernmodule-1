#include <iostream>
#include <SFML/Graphics.hpp>
#include "ship.h"
#include "Vector2.h"
#include "player.h"
#include "entity.h"

int main(int argc, char** argv)
{
    int width = 640;
    int height = 480;
    Player p(width / 2.f, height, width, height);

    sf::CircleShape player(p.shapeSize / 2.f);
    player.setFillColor(sf::Color::Green);

    sf::RenderWindow window(sf::VideoMode(width, height), "Uwu Invaz0rs");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        // Move right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p.MoveRight();
        }

        // Move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p.MoveLeft();
        }

        window.clear();
        window.draw(player);
        player.setPosition(p.GetPosition().x(), p.GetPosition().y());
        window.display();
    }

    return 0;
}