// Made by Ravi Bechoe

#include "Program.h"
#include <iostream>
#include <Windows.h>
#include <random>
#include <cmath>
#include <chrono>

Program::Program()
{
    running = true;
    frameCount = 0;
    frameRate = 1;
}

void Program::Update()
{
    frameCount++;

    // end program
    if (GetAsyncKeyState(VK_ESCAPE)) // doesnt work in cmd but does work in VS Code
    {
        running = false;
    }
}

// clear console
void Program::CleanConsole()
{
    system("cls");
}

// generate random number
int Program::GetRandomValue(int length) 
{
    int value = 0;
    int loopLength = length + 3;
    int64_t ran = 0;

    // add a digit every time the user had a correct answer
    for (int i = 0; i < loopLength; i++) 
    {
        //rand was not random, this is why I used my own method that is slightly more random
        /*
            divide by 1000 to get rid of miliseconds
            times loop count to not get the same number
            mod by 9 to get a value from 0-8
            added with 1 to get a value from 1-9
            we dont want zero, because zero doesnt get added!
        */
        ran = std::chrono::system_clock::now().time_since_epoch().count() / 1000 * (i + 1) % 9 + 1;
        //cout << ran << endl;
        int power = pow(10, i);
        ran = ran * power;
        value += ran;
        ran = 0;
    }

    return value;
}

// return frame count
int Program::GetFrameCount() 
{
    return frameCount;
}

// set a new state for program
void Program::SetState(bool newState) 
{
    running = newState;
}

// return program state
bool Program::GetState()
{
    return running;
}

// return frame rate
int Program::GetFPS()
{
    return frameRate;
}