#include "player.h"

void Player::MoveLeft()
{
    if (acceleration > -1) 
    {
        acceleration -= force;
    }
}

void Player::MoveRight()
{
    if (acceleration < 1) 
    {
        acceleration += force;
    }
}

void Player::Update() 
{
    // Move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        MoveRight();
    }
    // Move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        MoveLeft();
    }

    // TODO space to shoot

    UpdateMovement();
}

void Player::UpdateMovement()
{    
    // render ship sprite based on acceleration
    // clamp xpos within game borders and low acceleration rate before updating player pos
    float newX = GetPosition().x() + horizontalSpeed * acceleration;
    if (newX >= windowWidth - shapeSize) newX = windowWidth - shapeSize;
    if (newX <= 0) newX = 0;
    if (acceleration > 0) acceleration -= friction;
    if (acceleration < 0) acceleration += friction;
    UpdatePosition(newX, GetPosition().y());
}