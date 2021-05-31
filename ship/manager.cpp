#include "manager.h"

using namespace std::chrono;

GameManager::GameManager(Player& player, int width, int height)
{
    p = player;
    this->width = width;
    this->height = height;
    enemies.reserve(enemyMax);
    for (int i = 0; i < enemyMax; i++) 
    {
        float size = 40 + i * 3;
        enemies.emplace_back(rand() % width - size, -200 - i * 40 - size, width, height);
        enemies[i].Initialize(size);
    }
    p.horizontalSpeed = 10.f;
}

// update function called every frame
void GameManager::Update(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }

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
        enemies[i].ColorCycle();
        enemy.setFillColor(enemies[i].myColor);
        enemy.setPosition(enemies[i].GetPosition().x(), enemies[i].GetPosition().y());
        window.draw(enemy);
    }

    // draw UI stuff - top layer
    sf::RectangleShape topBar;
    topBar.setSize(sf::Vector2f(width, 50));
    topBar.setFillColor(sf::Color(50, 50, 50));
    window.draw(topBar);

    sf::Font font;
    font.loadFromFile("arial.ttf");
    std::string scr = "Score: " + score;
    std::string lvs = "Lives: " + lives;
    sf::Text scoreTxt(scr, font);
    scoreTxt.setCharacterSize(24);
    scoreTxt.setFillColor(sf::Color(150, 150, 150));
    scoreTxt.setPosition(10, 10);
    sf::Text livesTxt(lvs, font);
    livesTxt.setCharacterSize(24);
    livesTxt.setFillColor(sf::Color(150, 150, 150));
    livesTxt.setPosition(width - 200, 10);
    window.draw(scoreTxt);
    window.draw(livesTxt);
}