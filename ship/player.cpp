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
    // make bullet pool
    // when bullet active travel up
    // once bullet collides or out of bounds go inactive
    // award points upon death of enemy


    UpdateMovement();
}

void Player::UpdateMovement()
{        
    float newX = GetPosition().x() + horizontalSpeed * acceleration;
    if (newX >= windowWidth - shapeSize) newX = windowWidth - shapeSize;
    if (newX <= 0) newX = 0;
    if (acceleration > 0) acceleration -= friction;
    if (acceleration < 0) acceleration += friction;
    if (acceleration < 0.02f && acceleration > -0.02f) acceleration = 0;
    UpdatePosition(newX, GetPosition().y());
}