// Made by Ravi

#pragma once
#include "NPC.h"

class Elf : public NPC
{
    public:
        Elf(std::string newName, int newStrength) : NPC(newName, newStrength) {};
        void SetAgility(int amount);
        int GetAgility();

    private:
        int agility;
};