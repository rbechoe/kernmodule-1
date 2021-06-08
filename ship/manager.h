#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <chrono>
#include "ship.h"
#include "vector2.h"
#include "player.h"
#include "entity.h"
#include "enemy.h"
#include "bullet.h"

class GameManager
{
    public:
        GameManager(Player& player, int width, int height);
        GameManager() = default;
        ~GameManager();
        Player p;
        Vector2 colCheck;
        int width;
        int height;
        int enemyAmount = 1; // increments over time
        int enemyMax = 5;
        int bulletAmount = 10;
        int curBullet = 0;
        int score = 0;
        int lives = 10;
        int gameState = 0; // 0 start screen, 1 game screen, 2 win screen, 3 lose screen
        int winTreshold = 50;
        int shootCd = 0;
        std::vector<Enemy> enemies;
        std::vector<Bullet> bullets;
        void Update(sf::RenderWindow& window);
        void AddScore(int amount);
        void LoseLives();
        sf::Texture eText;
        sf::Texture pTextLeft;
        sf::Texture pTextRight;
        sf::Texture pTextMid;
        sf::Music* enemyHit;
        sf::Music* music;
        sf::Music* playerShoot;
        sf::Music* playerHit;
    private:
};