#include <cmath>
#include "Vector2.h"

// initialize vector 2 with x and y values
Vector2::Vector2(float newX, float newY)
{
    xValue = newX;
    yValue = newY;
}

/// get x
float Vector2::x()
{
    return xValue;
}

// get y
float Vector2::y()
{
    return yValue;
}

// get magnitude
float Vector2::magnitude()
{
    return sqrt(sqrMagnitude());
}

// get square magnitude
float Vector2::sqrMagnitude()
{
    float sqrX = pow(xValue, 2);
    float sqrY = pow(yValue, 2);
    return (sqrX + sqrY);
}

// get dot product from own vector2 + all params
float Vector2::dotProduct(Vector2 vectors[], int size)
{
    float r;
    r = xValue * yValue;
    for (int i = 0; i < size; i++) 
    {
        r += vectors[i].x() * vectors[i].y();
    }

    return r;
}

// check for collision between 2 vectors 
float collisionDetection(Vector2 vectorA, Vector2 vectorB, float r1, float r2)
{
    Vector2 v((vectorB.x() - vectorA.x()), (vectorB.y() - vectorA.y()));
    float f(sqrt(pow(v.x(), 2) + pow(v.y(), 2)));
    float r(r1 - r2 - f);
    
    if (r > 0) return 0; // no collision
    if (r == 0) return 1; // right on the edge
    if (r < 0) return 2; // collision

    return 0;
}

// update x and y values with new values
void Vector2::OverrideValues(float newX, float newY)
{
    xValue = newX;
    yValue = newY;
}

// get normalized value of vector2
Vector2 Vector2::normalized()
{
    float xNormal = xValue / magnitude();
    float yNormal = yValue / magnitude();
    Vector2 v(xNormal, yNormal);
    return v;
}

//------VECTOR2 PARAM OPERATORS-------
// add vector2 to current vector2
Vector2 Vector2::operator+(const Vector2& vectorToAdd) const
{
    Vector2 v(xValue + vectorToAdd.xValue, yValue + vectorToAdd.yValue);
    return v;
}

// add vector2 to current vector2
Vector2& Vector2::operator+=(const Vector2& vectorToAdd)
{
    this->OverrideValues(xValue + vectorToAdd.xValue, yValue + vectorToAdd.yValue);
    return *this;
}

// multiply vector2 to current vector2
Vector2 Vector2::operator*(const Vector2& multiplyVal) const
{
    Vector2 v(xValue * multiplyVal.xValue, yValue * multiplyVal.yValue);
    return v;
}

// mutliply vector2 to current vector2
Vector2& Vector2::operator*=(const Vector2& multiplyVal)
{
    this->OverrideValues(xValue * multiplyVal.xValue, yValue * multiplyVal.yValue);
    return *this;
}

//------SINGLE PARAM OPERATORS-------
// add float to current vector2
Vector2 Vector2::operator+(const float& addVal) const
{
    Vector2 v(xValue + addVal, yValue + addVal);
    return v;
}

// add float to current vector2
Vector2& Vector2::operator+=(const float& addVal)
{
    this->OverrideValues(xValue + addVal, yValue + addVal);
    return *this;
}

// multiply float to current vector2
Vector2 Vector2::operator*(const float& multiplyVal) const
{
    Vector2 v(xValue * multiplyVal, yValue * multiplyVal);
    return v;
}

// mutliply float to current vector2
Vector2& Vector2::operator*=(const float& multiplyVal)
{
    this->OverrideValues(xValue * multiplyVal, yValue * multiplyVal);
    return *this;
}

Vector2::~Vector2()
{
    // clean up?
}