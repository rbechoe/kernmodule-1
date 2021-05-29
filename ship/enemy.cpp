#include "enemy.h"
#include <iostream>

void Enemy::UpdateMovement()
{
    // fall on y axis based on gravity
    // bounce on x axis
    UpdatePosition(position.x(), position.y() + movementSpeed);

    if (position.y() >= windowHeight) 
    {
        // spawn back up
        float xpos = rand() % windowWidth - shapeSize;
        if (xpos < shapeSize) xpos = shapeSize;
        UpdatePosition(xpos, 0 - shapeSize);
    }
}