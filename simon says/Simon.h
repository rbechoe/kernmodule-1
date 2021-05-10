// Made by Ravi Bechoe

#pragma once
#include <string>
#include "Program.h"

class SimonSays
{
    public:
        SimonSays();
        void Start(Program);
        void Update(Program);
        void CleanUp();
        void Says();
        ~SimonSays();

    private: 
        int value;
        int input;
        int correctAnswers;
        Program program;
};