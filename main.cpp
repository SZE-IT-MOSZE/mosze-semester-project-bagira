#include <string>

#include "include/Game.h"

int main(int argc,char** argv){
    std::string filename = "Story.json";
    Game game(filename);
    game.run();
}

// START WITH
// g++ -std=c++17 main.cpp include/*.cpp
