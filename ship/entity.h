#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>

class Entity 
{
    public:
        Entity(float xPos, float yPos, int windowWidth, int windowHeight);
        Entity() = default;
        int windowWidth; 
        int windowHeight;
        float verticalSpeed;
        float horizontalSpeed;
        float acceleration;
        float shapeSize;
        float force;
        float friction;
        void UpdatePosition(float newX, float newY);
        Vector2 GetPosition();
        Vector2 position;
        sf::Color myColor;
    private: 
};