// Made by Ravi Bechoe

#pragma once
#include <string>

class Program
{
    public:
        Program();
        void SetState(bool);
        void Update();
        void CleanConsole();
        bool GetState();
        int GetFPS();
        int GetFrameCount();
        int GetRandomValue(int);

    private:
        bool running;
        int frameCount;
        int frameRate;
};