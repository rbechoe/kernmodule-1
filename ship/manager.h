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
        int enemyAmount = 10;
        int enemyMax = 10;
        std::vector<Enemy> enemies;
        void Update(sf::RenderWindow& window);
    private:
};