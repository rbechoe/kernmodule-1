// written by Ravi

#include "Inventory.h"

void Inventory::AddItem(std::string item)
{
    items.push_back(item);
}

std::string Inventory::GetItem(int item) 
{
    return items[item];
}

std::vector<std::string> Inventory::GetItems()
{
    return items;
}