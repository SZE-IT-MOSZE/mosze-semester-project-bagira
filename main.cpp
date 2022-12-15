#include <string>
#include <windows.h>

#include "include/Game.h"

int main(int argc,char** argv){
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    std::string filename = "Story.json";
    Game game(filename);
    game.run();
}

// START WITH
// g++ -std=c++17 main.cpp include/*.cpp