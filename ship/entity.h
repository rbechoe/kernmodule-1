#pragma once
#include "Vector2.h"

class Entity 
{
    public:
        Entity(float xPos, float yPos, int windowWidth, int windowHeight);
        Entity() = default;
        int windowWidth; 
        int windowHeight;
        float movementSpeed;
        float shapeSize;
        void UpdatePosition(float newX, float newY);
        Vector2 GetPosition();
        Vector2 position;
    private: 
};