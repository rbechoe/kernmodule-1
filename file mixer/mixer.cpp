// Made by Ravi Bechoe

#include "mixer.h"
#include <fstream>
#include <iostream>

using namespace std;

Mixer::Mixer() 
{
    linesA = "textlinesa.txt";
    linesB = "textlinesb.txt";
    linesB = "textlinesc.txt";
}

// read from file
void Mixer::ReadWrite()
{
    string textA;
    string textB;

    // read file A
    ifstream FileA(linesA);
    while (getline (FileA, textA)) {
        cout << textA << endl;
    }
    FileA.close();

    // read file B
    ifstream FileB(linesB);
    while (getline (FileB, textB)) {
        cout << textB << endl;
    }
    FileB.close();

    // write to file C
    ofstream MyFile(linesC);
    // files have 10 lines each
    for (int i = 0; i < 10; i++) 
    {
        MyFile << textA[i] << endl;
        MyFile << textB[i] << endl;
    }
    MyFile.close();
}