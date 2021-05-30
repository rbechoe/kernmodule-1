#include "enemy.h"
#include <iostream>

void Enemy::UpdateMovement()
{
    // fall on y axis based on gravity
    // bounce on x axis by flipping x speed
    UpdatePosition(position.x(), position.y() + verticalSpeed);

    if (position.y() >= windowHeight) 
    {
        // spawn back up
        float xpos = rand() % windowWidth - shapeSize;
        if (xpos < shapeSize) xpos = shapeSize;
        UpdatePosition(xpos, 0 - shapeSize);
    }
}