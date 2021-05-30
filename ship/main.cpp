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

// window settings
int width = 640;
int height = 480;
sf::RenderWindow window(sf::VideoMode(width, height), "UwU Invaz0rs");
// fps settings
int fps = 60;
unsigned long frameDelay = 1000 / fps;
unsigned long frameStart;
int frameTime;
// player
Player p(width / 2.f, height, width, height);
// enemies
int enemyAmount = 10;
int enemyMax = 10;
std::vector<Enemy> enemies;

int main(int argc, char** argv)
{
    Start();

    while (window.isOpen())
    {
        Update();
    }

    return 0;
}

// start function only called once
void Start ()
{
    enemies.reserve(enemyMax);
    for (int i = 0; i < enemyMax; i++) 
    {
        float size = 40 + i * 3;
        enemies.emplace_back(rand() % width - size, -200 - i * 40 - size, width, height);
        enemies[i].shapeSize = size;
        enemies[i].verticalSpeed = 5.f;
        enemies[i].horizontalSpeed = 5.f;
        enemies[i].myColor = sf::Color(255, rand() % 100, rand() % 100);
    }
    p.horizontalSpeed = 10.f;
}

// update function called every frame
void Update()
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

    window.clear();

    // player - bottom layer
    p.Update();
    sf::CircleShape player(p.shapeSize / 2.f);
    player.setFillColor(sf::Color::Green);
    player.setPosition(p.GetPosition().x(), p.GetPosition().y());
    window.draw(player);

    // enemies - middle layer
    for (int i = 0; i < enemyAmount; i++) 
    {
        sf::CircleShape enemy(enemies[i].shapeSize / 2.f);
        enemies[i].UpdateMovement();
        enemy.setFillColor(enemies[i].myColor);
        enemy.setPosition(enemies[i].GetPosition().x(), enemies[i].GetPosition().y());
        window.draw(enemy);
    }

    // draw UI stuff - top layer
    window.display();

    frameTime = duration_cast<milliseconds>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch()).count() - frameStart;
    if (frameDelay > frameTime) 
    {
        Sleep(frameDelay - frameTime);
    }
}