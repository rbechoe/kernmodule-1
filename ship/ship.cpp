#include <iostream>
#include "ship.h"

Ship::Ship(int initialLoad) : load(initialLoad)
{

}

int Ship::getLoad() const
{
    return load;
}

void Ship::addLoad(int loadToAdd)
{
    load += loadToAdd;
}

Ship Ship::operator+(const int& laodToAdd) const
{
    Ship s(load + laodToAdd);
    return s;
}

Ship operator+(const Ship& lhs, const int& rhs)
{
    Ship s(lhs.getLoad() + rhs);
    return s;
}

Ship operator+(const int& lhs, const Ship& rhs)
{
    Ship s(rhs.getLoad() + lhs);
    return s;
}

Ship& Ship::operator+=(const int& loadToAdd)
{
    load += loadToAdd;
    return *this;
}