#include "enemy.h"

void Enemy::MoveLeft()
{
    if (GetPosition().x() > 0) 
    {
        UpdatePosition(GetPosition().x() - movementSpeed, GetPosition().y());
    }
}

void Enemy::MoveRight()
{
    if (GetPosition().x() < (windowWidth - shapeSize)) 
    {
        UpdatePosition(GetPosition().x() + movementSpeed, GetPosition().y());
    }
}

void Enemy::UpdateMovement()
{
    // fall on y axis based on gravity
    // bounce on x axis
}