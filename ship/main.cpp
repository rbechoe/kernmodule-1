#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <windows.h>
#include "manager.h"
#include "player.h"

using namespace std::chrono;

// window settings
int width = 640;
int height = 480;
sf::RenderWindow window(sf::VideoMode(width, height), "UwU Invaz0rs");
// fps settings
int fps = 240;
unsigned long frameDelay = 1000 / fps;
unsigned long frameStart;
int frameTime;
// game things
Player player(width / 2.f, height, width, height);
GameManager gm(player, width, height);

int main(int argc, char** argv)
{
    while (window.isOpen())
    {
        frameStart = duration_cast<milliseconds>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch()).count();

        window.clear();
        gm.Update(window);
        window.display();
        
        frameTime = duration_cast<milliseconds>(time_point_cast<milliseconds>(high_resolution_clock::now()).time_since_epoch()).count() - frameStart;
        if (frameDelay > frameTime) Sleep(frameDelay - frameTime);
    }

    return 0;
}