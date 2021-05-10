// written by Ravi

#pragma once
#include <string>
#include "Inventory.h"
#include "Inventory.cpp"

class NPC
{
    public:
        NPC(std::string newName, int newStrength);
        ~NPC();
        Inventory* inventory = new Inventory();
        std::string GetName();
        int GetStrength();

    private:
        std::string name;
        int strength;
};