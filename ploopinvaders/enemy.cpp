#include "enemy.h"
#include <iostream>

// set start color cycle
void Enemy::Initialize(float size)
{
    verticalSpeed = 5.f;
    horizontalSpeed = 0.f;
    red = 255;
    green = rand() % 100;
    blue = rand() % 100;

    int ran = rand() % 100;
    if (ran > 50) incrementSpeed = true;
    maxSpeed = .5f;
    acceleration = 0.005f;

    int val = rand() % 80;
    if (val < 20) 
        colorState = 0;
    else if (val < 40)
        colorState = 1;
    else if (val < 60)
        colorState = 2;
    else
        colorState = 3;
}

void Enemy::UpdateMovement()
{
    // fall on y axis based on gravity
    // bounce on x axis by flipping x speed
    UpdatePosition(position.x() + horizontalSpeed, position.y() + verticalSpeed);

    if (position.y() >= windowHeight) 
    {
        // spawn back up
        float xpos = rand() % windowWidth - shapeSize;
        if (xpos < shapeSize) xpos = shapeSize;
        UpdatePosition(xpos, 0 - shapeSize);
        died = true;
    }

    // check if enemy is out of bounds to inverse bool
    if (position.x() > windowWidth - shapeSize) 
    {
        incrementSpeed = false;
        force = 0;
        horizontalSpeed = 0;
    }
    if (position.x() < 0) 
    {
        incrementSpeed = true;
        force = 0;
        horizontalSpeed = 0;
    }
    float constrainedX = position.x();
    constrainedX = (constrainedX > windowWidth - shapeSize) ? windowWidth - shapeSize : constrainedX;
    constrainedX = (constrainedX < 0) ? 0 : constrainedX;
    UpdatePosition(constrainedX, position.y());

    // TODO: calculate speed based on distance from position to border
    if (incrementSpeed) 
    {
        // increase speed with accel factor
        if (force < maxSpeed) force += acceleration;
    }
    else 
    {
        // decrease speed with accel factor
        if (force > -maxSpeed) force -= acceleration;
    }
    // clamp force
    if (force > maxSpeed) force = maxSpeed;
    if (force < -maxSpeed) force = -maxSpeed;
    horizontalSpeed += force;
}

// cycle through colors
void Enemy::ColorCycle()
{
    // avoid pure white and red
    switch(colorState) 
    {
        case 0:
            if (green >= 200) colorState = 1;
            if (green < 200) green++;
            break;
        case 1:
            if (blue >= 200) colorState = 2;
            if (blue < 200) blue++;
            break;
        case 2:
            if (green <= 50) colorState = 3;
            if (green > 50) green--;
            break;
        case 3:
            if (blue <= 50) colorState = 0;
            if (blue > 50) blue--;
            break;
    }

    myColor = sf::Color(red, green, blue);
}