#pragma once
#include "entity.h"

class Bullet : public Entity
{
    public:
        Bullet(float xPos, float yPos, int windowWidth, int windowHeight) : Entity(xPos, yPos, windowWidth, windowHeight) {};
        void UpdateMovement();
        bool used;
    private: 
};