#include <cmath>
#include "Vector2.h"

Vector2::Vector2(float newX, float newY)
{
    xValue = newX;
    yValue = newY;
}

float Vector2::x()
{
    return xValue;
}

float Vector2::y()
{
    return yValue;
}

float Vector2::magnitude()
{
    return sqrt(sqrMagnitude());
}

float Vector2::sqrMagnitude()
{
    float sqrX = pow(xValue, 2);
    float sqrY = pow(yValue, 2);
    return (sqrX + sqrY);
}

// includes own x and y vals
float Vector2::dotProduct(Vector2 vectors[])
{
    float size = sizeof(vectors) / sizeof(*vectors);
    float r;

    r = xValue * yValue;
    for (int i = 0; i < size; i++) 
    {
        r += vectors[i].x() * vectors[i].y();
    }

    return r;
}

float collisionDetection(Vector2 vectorA, Vector2 vectorB)
{
    Vector2 v((vectorB.x() - vectorA.x()), (vectorB.y() - vectorA.y()));
    float f(sqrt(pow(v.x(), 2) + pow(v.y(), 2)));
    // TODO r1 - r2 - f
    // if < 0 collision
    // if = 0 right on the edge
    // if > 0 no collision
}

Vector2 Vector2::normalized()
{
    float xNormal = xValue / magnitude();
    float yNormal = yValue / magnitude();
    Vector2 v(xNormal, yNormal);;
    return v;
}

Vector2 Vector2::operator+(const Vector2& vectorToAdd) const
{
    Vector2 v(xValue + vectorToAdd.xValue, yValue + vectorToAdd.yValue);
    return v;
}

Vector2& Vector2::operator+=(const Vector2& vectorToAdd)
{
    Vector2 v(xValue + vectorToAdd.xValue, yValue + vectorToAdd.yValue);
    return v;
}

Vector2 Vector2::operator*(const Vector2& multiplyVal) const
{
    Vector2 v(xValue * multiplyVal.xValue, yValue * multiplyVal.yValue);
    return v;
}

Vector2& Vector2::operator*=(const Vector2& multiplyVal)
{
    Vector2 v(xValue * multiplyVal.xValue, yValue * multiplyVal.yValue);
    return v;
}

void Vector2::OverrideValues(float newX, float newY)
{
    xValue = newX;
    yValue = newY;
}

Vector2::~Vector2()
{
    // clean up?
}