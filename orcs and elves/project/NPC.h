// written by Ravi

#pragma once
#include <string>

class NPC
{
    public:
        NPC(std::string newName, int newStrength);
        std::string GetName();
        int GetStrength();

    private:
        std::string name;
        int strength;
};