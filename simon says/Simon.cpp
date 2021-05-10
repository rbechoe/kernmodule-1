// Made by Ravi Bechoe

#include "Simon.h"
#include <iostream>
#include <Windows.h>

using namespace std;

// initialize program
SimonSays::SimonSays()
{
    correctAnswers = 0;
    cout << "Please enter the code that Simon says" << endl;
    Sleep(5000); // wait 1 sec
}

// start function
void SimonSays::Start(Program _program)
{
    program.CleanConsole();
    program = _program;
    Says();
}

// update function
void SimonSays::Update(Program _program)
{
    program = _program; // get updated state of program

    cout << "What did Simon say?" << endl;
    cin >> input;
    if (input == value) 
    {
        cout << "That is correct!" << endl;
        correctAnswers++;
        CleanUp();
        Says();
    }
    else 
    {
        cout << "Simon did not say that!" << endl;
        cout << "Correct answers: " << correctAnswers << endl;
        Sleep(5000); // wait 5 sec
        exit(0);
    }

    // if answer is correct increase range x10 and increment correctAnswers +1
    // if answer is wrong print combo and close program
}

// Simon says function
void SimonSays::Says() 
{
    value = program.GetRandomValue(correctAnswers);
    cout << "Simon says: " << value << endl;
    CleanUp();
}

// cleanup console after 2 sec
void SimonSays::CleanUp()
{
    Sleep(2000); // wait 2 sec
    program.CleanConsole();
}

// destructor
SimonSays::~SimonSays()
{
    std::cout.clear();
    cout << "Ending program" << endl;
}