// written by Ravi

#pragma once
#include <string>
#include <vector>

class Inventory 
{
    public: 
        void AddItem(std::string item);
        std::string GetItem(int item);
        std::vector<std::string> GetItems();

    private:
        std::vector<std::string> items;
};