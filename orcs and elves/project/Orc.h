// Made by Ravi

#pragma once
#include "NPC.h"

class Orc : public NPC
{
    public:
        Orc(std::string newName, int newStrength) : NPC(newName, newStrength) {};
        void SetMinions(int amount);
        int GetMinions();

    private:
        int minions;
};