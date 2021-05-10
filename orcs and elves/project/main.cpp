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

    Elf elf("High Elf", 8);
    elf.SetAgility(10);
    cout << "A " << elf.GetName() << " has spawned with " << elf.GetStrength() << " strength.\n";

    return 0;
}