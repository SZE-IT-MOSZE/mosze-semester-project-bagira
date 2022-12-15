/**
 * @file User.h
 * @author Bagira csapat
 * @brief User class
 * @version 1.0
 * @date 2022-11-15
 */
#pragma once

#include<string>


#define STANDARD_HP 100;
#define STANDARD_MORALE 15;

/**
 * @brief Represents an User
 * 
 * This class contains the individual User that the user can choose from
 * 
 */
class User{
    std::string name; ///< Text display of the answer
    const int hp; ///< The hp value for the answer
    const int morale; ///< The morale value for the answer

public:
/**
 * @brief Construct a new User object
 * 
 * @param hp 
 * @param morale 
 */
    User() : hp(100), morale(15) {}

/**
 * @brief Get the Name attribute of an User
 * 
 * @return std::string 
 */
    std::string getName() const;
/**
 * @brief Get the hp attribute of an User
 * 
 * @return int 
 */
    int getHp() const { return hp; }
/**
 * @brief Get the Morale attribute of an User
 * 
 * @return int 
 */
    int getMorale() const { return morale; }

    void setName (std::string name) { name = name; }

    void setHp(int hp) { hp += hp; }

    void setMorale(int morale) {morale += morale; }
};