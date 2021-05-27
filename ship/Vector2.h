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
        float sqrMagnitude();
        float dotProduct(Vector2 vectors[], int size);
        float collisionDetection(Vector2 vectorA, Vector2 vectorB);
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

// TODO: make it more applicable
// angle calculations