// Made by Ravi Bechoe

#include "Simon.h"
#include "Program.h"
#include "Simon.cpp"
#include "Program.cpp"
#include <iostream>
#include <Windows.h>

int main() 
{
    std::cout << "Starting up..." << std::endl;

    Program program;
    SimonSays simonSays;
    simonSays.Start(program);

    while (program.GetState())
    {
        // limit frame rate
        float wait = 1000 / program.GetFPS();
        Sleep(wait);

        // update classes and pass updated classes to those who need it
        program.Update();
        simonSays.Update(program);
    }

    return 0;
}