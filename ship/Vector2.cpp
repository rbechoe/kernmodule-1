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

Vector2 Vector2::normalized()
{
    float xNormal = xValue / magnitude();
    float yNormal = yValue / magnitude();
    Vector2 r(xNormal, yNormal);;
    return r;
}

Vector2::~Vector2()
{
    // clean up?
}