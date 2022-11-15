/**
 * @file Option.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include<string>

/**
 * @brief 
 * 
 */
class Option{
    std::string answer;
    const int hp;
    const int morale;

public:
/**
 * @brief Construct a new Option object
 * 
 * @param answer 
 * @param hp 
 * @param morale 
 */
    Option(std::string answer, int hp, int morale);
/**
 * @brief Get the Answer object
 * 
 * @return std::string 
 */
    std::string getAnswer() const;
/**
 * @brief Get the Hp object
 * 
 * @return int 
 */
    int getHp() const { return hp; }
/**
 * @brief Get the Morale object
 * 
 * @return int 
 */
    int getMorale() const { return morale; }
};