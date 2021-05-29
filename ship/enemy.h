#pragma once
#include "entity.h"

class Enemy : public Entity
{
    public:
        Enemy(float xPos, float yPos, int windowWidth, int windowHeight) : Entity(xPos, yPos, windowWidth, windowHeight) {};
        void UpdateMovement();
    private: 
};