#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include "ship.h"
#include "vector2.h"
#include "player.h"
#include "entity.h"
#include "enemy.h"

class GameManager
{
    public:
        GameManager(Player& player, int width, int height);
        Player p;
        int width;
        int height;
        int enemyAmount = 10;
        int enemyMax = 10;
        int score = 0;
        int lives = 3;
        std::vector<Enemy> enemies;
        void Update(sf::RenderWindow& window);
    private:
};