#include "manager.h"

using namespace std;
using namespace std::chrono;

GameManager::GameManager(Player& player, int width, int height)
{
    // set basics
    p = player;
    p.horizontalSpeed = 10.f;
    this->width = width;
    this->height = height;
    colCheck.OverrideValues(1, 1);
    // load textures
    eText.loadFromFile("resource/enemy.png");
    pTextLeft.loadFromFile("resource/player_left.png");
    pTextRight.loadFromFile("resource/player_right.png");
    pTextMid.loadFromFile("resource/player_normal.png");
    // reserve enemy data
    enemies.reserve(enemyMax);
    for (int i = 0; i < enemyMax; i++) 
    {
        float size = 40 + i * 3;
        enemies.emplace_back(rand() % width - size, -200 - i * height / enemyMax - size, width, height);
        enemies[i].Initialize(size);
    }
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

    if (gameState == 0)
    {
        // start game
        sf::Font font;
        font.loadFromFile("resource/retrofont.ttf");
        string str = "Welcome trooper\n";
        str += "Dodge and kill the enemies\n";
        str += "You win at " + to_string(winTreshold) + " points\n";
        str += "Use A and D or arrow keys to move\n";
        str += "Press spacebar to start game\n";
        str += "Press escape to end game\n";
        sf::Text scoreTxt(str, font);
        scoreTxt.setCharacterSize(18);
        scoreTxt.setFillColor(sf::Color(150, 150, 150));
        scoreTxt.setPosition(25, 25);
        window.draw(scoreTxt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            gameState = 1;
        }
    }
    else if (gameState == 1) 
    {
        // player - bottom layer
        p.Update();
        sf::Sprite player;
        player.setPosition(p.GetPosition().x(), p.GetPosition().y());
        if (p.acceleration > 0) player.setTexture(pTextRight);
        else if (p.acceleration < 0) player.setTexture(pTextLeft);
        else player.setTexture(pTextMid);
        player.setScale(0.1f, 0.1f);
        window.draw(player);

        // enemies - middle layer
        for (int i = 0; i < enemyAmount; i++) 
        {
            enemies[i].UpdateMovement();
            enemies[i].ColorCycle();
            
            sf::Sprite enemy;
            enemy.setTexture(eText);
            enemy.setPosition(enemies[i].GetPosition().x(), enemies[i].GetPosition().y());
            enemy.setColor(enemies[i].myColor);
            enemy.setScale(0.1f, 0.1f);

            // check if enemy died
            if (enemies[i].died) 
            {
                enemies[i].died = false;
                AddScore(3);
            }

            // check if player died
            bool hasCol = colCheck.collisionDetection(enemies[i].GetPosition(), p.GetPosition(), enemies[i].shapeSize, p.shapeSize);
            if (hasCol == true) 
            {
                enemies[i].UpdatePosition(enemies[i].GetPosition().x(), 0 - enemies[i].shapeSize);
                LoseLives();
            }
            window.draw(enemy);
        }

        // draw UI stuff - top layer
        sf::RectangleShape topBar;
        topBar.setSize(sf::Vector2f(width, 50));
        topBar.setFillColor(sf::Color(50, 50, 50));
        window.draw(topBar);

        sf::Font font;
        font.loadFromFile("resource/retrofont.ttf");
        string scr = "Score " + to_string(score);
        string lvs = "Lives " + to_string(lives);
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
    else if (gameState == 2) 
    {
        // victory
        sf::Font font;
        font.loadFromFile("resource/retrofont.ttf");
        string str = "Congratulations\n"; 
        str += "You scored " + to_string(score) + " points\n";
        str += "Press escape to end game\n";
        sf::Text scoreTxt(str, font);
        scoreTxt.setCharacterSize(24);
        scoreTxt.setFillColor(sf::Color(150, 150, 150));
        scoreTxt.setPosition(25, 25);
        window.draw(scoreTxt);
    }
    else if (gameState == 3) 
    {
        // lost
        sf::Font font;
        font.loadFromFile("resource/retrofont.ttf");
        string str = "You lost\n";
        str += "You only scored " + to_string(score) + " points\n";
        str += "Press escape to end game\n";
        sf::Text scoreTxt(str, font);
        scoreTxt.setCharacterSize(24);
        scoreTxt.setFillColor(sf::Color(150, 150, 150));
        scoreTxt.setPosition(25, 25);
        window.draw(scoreTxt);
    }
}

void GameManager::AddScore(int amount)
{
    score += amount;
}

void GameManager::LoseLives()
{
    lives--;
    if (lives <= 0) gameState = (score > winTreshold) ? 2 : 3;
}