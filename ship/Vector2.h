#pragma once

class Vector2
{
    public:
        Vector2(float newX, float newY);
        ~Vector2();
        float x();
        float y();
        float magnitude();
        float sqrMagnitude();
        float dotProduct(Vector2 vectors[]);
        float collisionDetection(Vector2 vectorA, Vector2 vectorB);
        Vector2 normalized();
        Vector2 operator+(const Vector2& vectorToAdd) const;
        Vector2& operator+=(const Vector2& vectorToAdd);
        Vector2 operator*(const Vector2& multiplyVal) const;
        Vector2& operator*=(const Vector2& multiplyVal);
        void OverrideValues(float newX, float newY);
    private:
        float xValue;
        float yValue;
};

// TODO: make it more applicable
// all operators with vector2 or single param
// angles calculaten
// collision detection