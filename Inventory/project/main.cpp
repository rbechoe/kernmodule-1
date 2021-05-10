// written by Ravi

#include <iostream>
#include "Orc.h"
#include "Elf.h"
#include "NPC.cpp"
#include "Orc.cpp"
#include "Elf.cpp"

using namespace std;

int main()
{
    Orc orc("Giant Orc", 10);
    orc.SetMinions(5);
    cout << "A " << orc.GetName() << " has spawned with " << orc.GetStrength() << " strength.\n";
    orc.inventory->AddItem("Dagger");
    cout << orc.GetName() << " has collected " << orc.inventory->GetItem(0) << ".\n";

    Elf elf("High Elf", 8);
    elf.SetAgility(10);
    cout << "A " << elf.GetName() << " has spawned with " << elf.GetStrength() << " strength.\n";
    elf.inventory->AddItem("Obsidian bow");
    cout << elf.GetName() << " has collected " << elf.inventory->GetItem(0) << ".\n";

    return 0;
}