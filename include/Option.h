/**
 * @file Option.h
 * @author Bagira csapat
 * @brief Option class
 * @version 1.0
 * @date 2022-11-15
 */
#pragma once

#include<string>
/**
 * @brief Represents an option
 * 
 * This class contains the individual option that the user can choose from
 * 
 */
class Option{
    std::string answer; ///< Text display of the answer
    const int hp; ///< The hp value for the answer
    const int morale; ///< The morale value for the answer

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
 * @brief Get the Answer attribute of an Option
 * 
 * @return std::string 
 */
    std::string getAnswer() const;
/**
 * @brief Get the hp attribute of an Option
 * 
 * @return int 
 */
    int getHp() const { return hp; }
/**
 * @brief Get the Morale attribute of an Option
 * 
 * @return int 
 */
    int getMorale() const { return morale; }
};