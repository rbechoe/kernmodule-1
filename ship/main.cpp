#include <iostream>
#include "ship.h"
#include "Vector2.h"
#include "ship.cpp"
#include "Vector2.cpp"

int main(int argc, char** argv)
{
    Ship ship(1500);
    ship += 600;
    std::cout << "Load: " << ship.getLoad() << "\n";

    Vector2 positionA(2, 5);
    Vector2 positionB(1, 7);
    std::cout << "X: " << positionA.x() << "\n";
    std::cout << "Magnitude: " << positionA.magnitude() << "\n";
    std::cout << "Square Magnitude: " << positionA.sqrMagnitude() << "\n";
    std::cout << "Normalized x: " << positionA.normalized().x() << "\n";

    return 0;
}