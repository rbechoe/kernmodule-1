#include "player.h"

void Player::MoveLeft()
{
    if (GetPosition().x() > 0) 
    {
        UpdatePosition(GetPosition().x() - movementSpeed, GetPosition().y());
    }
}

void Player::MoveRight()
{
    if (GetPosition().x() < (windowWidth - shapeSize)) 
    {
        UpdatePosition(GetPosition().x() + movementSpeed, GetPosition().y());
    }
}