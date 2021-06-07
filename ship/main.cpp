#include <SFML/Graphics.hpp>
#include <windows.h>
#include "manager.h"
#include "player.h"

using namespace std::chrono;

// window settings
int width = 640;
int height = 480;
sf::RenderWindow window(sf::VideoMode(width, height), "Space Invaders");
// fps settings
int fps = 30;
int frameCount = 0;
// game things
Player player(width / 2.f, height, width, height);
GameManager gm(player, width, height);

int main(int argc, char** argv)
{
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        if (frameCount / fps > 10 && gm.enemyAmount < gm.enemyMax)
        {
            frameCount = 0;
            gm.enemyAmount++;
        }

        frameCount++;
        window.clear();
        gm.Update(window);
        window.display();
    }

    return 0;
}