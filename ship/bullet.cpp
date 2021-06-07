#include "bullet.h"
#include <iostream>

void Bullet::UpdateMovement()
{
    // move against gravity
    if (used == true) 
    {
        UpdatePosition(position.x(), position.y() - verticalSpeed);

        if (position.y() < 0 - shapeSize) 
        {
            position.OverrideValues(0, -windowHeight);
            used = false;
        }
    }
}