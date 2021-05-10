// Made by Ravi Bechoe

#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Mixer 
{
    public: 
        Mixer();
        void ReadWrite();
    private:
        std::string linesA;
        std::string linesB;
        std::string linesC;
        std::string output;
};