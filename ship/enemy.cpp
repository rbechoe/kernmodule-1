#include "enemy.h"

void Enemy::UpdateMovement()
{
    // fall on y axis based on gravity
    // bounce on x axis
    UpdatePosition(position.x(), position.y() + 0.5f);

    if (position.y() >= windowHeight) 
    {
        // spawn back up
        UpdatePosition(position.x(), 0 - shapeSize);
    }
}