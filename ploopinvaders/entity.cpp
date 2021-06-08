#include "entity.h"

Entity::Entity(float xPos, float yPos, int windowWidth, int windowHeight)
{
    horizontalSpeed = 5.f;
    verticalSpeed = 5.f;
    shapeSize = 50.f;
    force = 0.03f;
    friction = 0.01f;
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