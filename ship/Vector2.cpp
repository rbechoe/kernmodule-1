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
    return sqrtMagnitude(xValue, yValue);
}

// get square magnitude
float Vector2::sqrMagnitude(float x, float y)
{
    float sqrX = pow(x, 2);
    float sqrY = pow(y, 2);
    return (sqrX + sqrY);
}

// get square root
float Vector2::sqrtMagnitude(float x, float y)
{
    return sqrt(sqrMagnitude(x, y));
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
bool Vector2::collisionDetection(Vector2 vectorA, Vector2 vectorB, float r1, float r2)
{
    Vector2 v((vectorB.x() - vectorA.x()), (vectorB.y() - vectorA.y()));
    float f(sqrtMagnitude(v.x(), v.y()));
    float r(r1 - r2 - f);

    // r > 0 is no collision, r == 0 is right on the edge, r < 0 is collision
    if (r < 0) return true;
    return false;
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