/**
 * @file Character.h
 * @author Bagira csapat
 * @brief Character class
 * @version 1.0
 * @date 2022-11-15
 */
#pragma once

#include<string>

#include "Option.h"

/**
 * @brief Represents a Character
 * 
 * This class contains the individual Character that the Character can choose from
 * 
 */
class Character{
    const int MAX_HP = 100; ///< Characters max HP, can't be more than that
    const int MAX_MORALE = 15; ///< Characters max morale, can't be more than that
    const std::string LOW_HP = "Nem érzed magad túl jól. Figyelj oda az egészségedre!"; ///< Character is under 20% HP
    const std::string LOW_MORALE = "Kezdesz stresszessé válni. Próbálj meg lazulni is kicsit!"; ///< Character is under 20% Morale


    std::string name; ///< Text display of the answer
    int hp; ///< The hp value for the answer
    int morale; ///< The morale value for the answer

public:
/**
 * @brief Construct a new Character object
 * 
 * @param hp 
 * @param morale 
 */
    Character() : hp(MAX_HP), morale(MAX_MORALE) {}
    Character(int hp, int morale) : hp(hp), morale(morale) {}

/**
 * @brief Get the Name attribute of an Character
 * 
 * @return std::string 
 */
    std::string getName() const;
/**
 * @brief Get the hp attribute of a Character
 * 
 * @return int 
 */
    int getHp() const { return hp; }
/**
 * @brief Get the Morale attribute of an Character
 * 
 * @return int 
 */
    int getMorale() const { return morale; }

/**
 * @brief Set the character's Name
 * 
 * @param CharacterName 
 */
    void setName (std::string CharacterName) { name = CharacterName; }

/**
 * @brief Set the character's HP
 * 
 * @param hp 
 */
    void setHp(int value) { hp = value; }

/**
 * @brief Set the character's Morale
 * 
 * @param morale 
 */
    void setMorale(int value) {morale = value; }

/**
 * @brief Get the character's Status
 * 
 */
    void getStatus() const;

/**
 * @brief update our character's stats based on their choice
 * 
 * @param optionData 
 */
    void updateCharacterStatus(Option optionData);

/**
 * @brief logic behind updating a single stat
 * 
 * @param stat 
 * @param modifierNumber modifier stat
 * @param maxStat const
 * @return with the calculated new stat
 */
    int updateStat(int stat, int modifierNumber, int maxStat);

/**
 * @brief Checks if the character can continue with their current stats
 * 
 * @return true then the story continues
 * @return false the character died / lost interest, the story ends
 */
    bool theCharacterCanContinue();

/**
 * @brief sends a warning message to the user when their characters stats are critical
 * A stat is critical when it's value drops below 20%
 * 
 * @param stat
 * @param maxStat const 
 * @param warningMessage const
 */
    void checkCharacterCondition(int stat, int maxStat, std::string warningMessage);

/**
 * @brief Display message if the character cannot continue
 * 
 */
    void initiateFinalDeath() const;
};