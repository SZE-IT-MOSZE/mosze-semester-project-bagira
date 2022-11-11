#pragma once

#include<string>

class Option{
    std::string answer;
    const int hp;
    const int morale;

public:
    Option(std::string answer, int hp, int morale);

    std::string getAnswer() const;

    int getHp() const { return hp; }

    int getMorale() const { return morale; }
};