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
        GameManager() = default;
        Player p;
        Vector2 colCheck;
        int width;
        int height;
        int enemyAmount = 1; // used to increment over time
        int enemyMax = 5;
        int score = 0;
        int lives = 10;
        int gameState = 0; // 0 start screen, 1 game screen, 2 win screen, 3 lose screen
        int winTreshold = 50;
        std::vector<Enemy> enemies;
        void Update(sf::RenderWindow& window);
        void AddScore(int amount);
        void LoseLives();
    private:
};