#pragma once
#include "entity.h"

class Player : public Entity
{
    public:
        Player(float xPos, float yPos, int windowWidth, int windowHeight) : Entity(xPos, yPos, windowWidth, windowHeight) {};
        void MoveLeft();
        void MoveRight();
        void UpdateMovement();
    private: 
};