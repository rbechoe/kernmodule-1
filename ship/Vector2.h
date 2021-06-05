#pragma once

class Vector2
{
    public:
        Vector2(float newX, float newY);
        Vector2() = default;
        ~Vector2();
        float x();
        float y();
        float magnitude();
        float sqrMagnitude(float x, float y);
        float sqrtMagnitude(float x, float y);
        float dotProduct(Vector2 vectors[], int size);
        bool collisionDetection(Vector2 vectorA, Vector2 vectorB, float r1, float r2);
        void OverrideValues(float newX, float newY);
        Vector2 normalized();

        // vector2 param operators
        Vector2 operator+(const Vector2& vectorToAdd) const;
        Vector2& operator+=(const Vector2& vectorToAdd);
        Vector2 operator*(const Vector2& multiplyVal) const;
        Vector2& operator*=(const Vector2& multiplyVal);

        // float param operators
        Vector2 operator+(const float& vectorToAdd) const;
        Vector2& operator+=(const float& vectorToAdd);
        Vector2 operator*(const float& multiplyVal) const;
        Vector2& operator*=(const float& multiplyVal);
    private:
        float xValue;
        float yValue;
};