#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <windows.h>
#include "ship.h"
#include "vector2.h"
#include "player.h"
#include "entity.h"
#include "enemy.h"

using namespace std::chrono;

// make object pool with enemies
// use counter for amount of active enemies
// update active enemies

int main(int argc, char** argv)
{
    int width = 640;
    int height = 480;

    // fps settings
    int fps = 60;
    unsigned long frameDelay = 1000 / fps;
    unsigned long frameStart;
    int frameTime;

    // enemies
    int enemyAmount = 3;
    int enemyMax = 10;
    std::vector<Enemy> enemies;
    enemies.reserve(enemyMax);
    for (int i = 0; i < enemyMax; i++) 
    {
        float size = 40 + i * 10;
        enemies.emplace_back(rand() % width - size, -200 - i * 40 - size, width, height);
        enemies[i].shapeSize = size;
        enemies[i].verticalSpeed = 10.f;
        enemies[i].horizontalSpeed = 5.f;
    }
    
    Player p(width / 2.f, height, width, height);
    p.horizontalSpeed = 10.f;

    sf::RenderWindow window(sf::VideoMode(width, height), "Uwu Invaz0rs");
    while (window.isOpen())
    {
        frameStart = duration_cast<milliseconds>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch()).count();

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
        p.UpdateMovement();

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

        frameTime = duration_cast<milliseconds>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch()).count() - frameStart;
        if (frameDelay > frameTime) 
        {
            Sleep(frameDelay - frameTime);
        }
    }

    return 0;
}