// written by Ravi

#include "NPC.h"

NPC::NPC(std::string newName, int newStrength)
{
    name = newName;
    strength = newStrength;
}

std::string NPC::GetName()
{
    return name;
}

int NPC::GetStrength()
{
    return strength;
}

NPC::~NPC()
{
    delete inventory;
}