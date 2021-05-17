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
        Vector2 normalized();
    private:
        float xValue;
        float yValue;
};