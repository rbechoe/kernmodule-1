#include "entity.h"

Entity::Entity(float xPos, float yPos, int windowWidth, int windowHeight)
{
    movementSpeed = .5f;
    shapeSize = 50.f;
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
    this->position.OverrideValues(xPos, yPos - shapeSize);
}

Vector2 Entity::GetPosition()
{
    return this->position;
}

void Entity::UpdatePosition(float newX, float newY)
{
    this->position.OverrideValues(newX, newY);
}