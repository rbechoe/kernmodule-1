#include <iostream>
#include "ship.h"
#include "Vector2.h"
#include "ship.cpp"
#include "Vector2.cpp"

int main(int argc, char** argv)
{
    Ship ship(1500);
    //ship = 300 + ship;
    ship += 600;
    std::cout << "Load: " << ship.getLoad();

    Vector2 position(2, 5);
    std::cout << "X: " << position.x() << "\n";
    std::cout << "Magnitude: " << position.magnitude() << "\n";
    std::cout << "Square Magnitude: " << position.sqrMagnitude() << "\n";
    std::cout << "Normalized x: " << position.normalized().x() << "\n";

    return 0;
}