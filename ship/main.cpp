#include <iostream>
#include <SFML/Graphics.hpp>
#include "ship.h"
#include "vector2.h"
#include "player.h"
#include "entity.h"
#include "enemy.h"

// make object pool with enemies
// use counter for amount of active enemies
// update active enemies

int main(int argc, char** argv)
{
    int width = 640;
    int height = 480;

    // enemies
    int enemyAmount = 3;
    int enemyMax = 10;
    std::vector<Enemy> enemies;
    enemies.reserve(enemyMax);
    for (int i = 0; i < enemyMax; i++) 
    {
        enemies.emplace_back(i * 20 + 100, -200 - i * 40, width, height);
        enemies[i].shapeSize = 40 + i * 10;
        enemies[i].movementSpeed = 1.f;
    }
    
    Player p(width / 2.f, height, width, height);

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

        // player
        sf::CircleShape player(p.shapeSize / 2.f);
        player.setFillColor(sf::Color::Green);
        player.setPosition(p.GetPosition().x(), p.GetPosition().y());
        window.draw(player);

        // enemies
        for (int i = 0; i < enemyAmount; i++) 
        {
            sf::CircleShape enemy(enemies[i].shapeSize / 2.f);
            enemies[i].UpdateMovement();
            enemy.setFillColor(sf::Color::Red);
            enemy.setPosition(enemies[i].GetPosition().x(), enemies[i].GetPosition().y());
            window.draw(enemy);
        }

        window.display();
    }

    return 0;
}