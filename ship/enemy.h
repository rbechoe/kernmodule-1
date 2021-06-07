#pragma once
#include "entity.h"

class Enemy : public Entity
{
    public:
        Enemy(float xPos, float yPos, int windowWidth, int windowHeight) : Entity(xPos, yPos, windowWidth, windowHeight) {};
        void Initialize(float size);
        void UpdateMovement();
        void ColorCycle();
        sf::Color myColor;
        int colorState;
        float maxSpeed;
        bool died;
        bool incrementSpeed;
    private: 
};