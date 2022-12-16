#include <string>
#include <iostream>

#include "Character.h"

void Character::getStatus() const {
    std::cout << "-----------------------------"
    "\nYour name: " << name << 
    "\nHP: " << hp << 
    "\nMorale: "  << morale <<
    "\n-----------------------------"
    << std::endl;
}

void Character::updateCharacterStatus(Option optionData) {
    //updating the characters HP and checking if they are in condition
    setHp(updateStat(getHp(), optionData.getHp(), MAX_HP));
    checkCharacterCondition(getHp(), MAX_HP, LOW_HP);
    
    //updating the characters Morale and checking if they are in condition
    setMorale(updateStat(getMorale(), optionData.getMorale(), MAX_MORALE));
    checkCharacterCondition(getMorale(), MAX_MORALE, LOW_MORALE);
}

int Character::updateStat(int stat, int modifierNumber, int maxStat) {
    int newStat = stat + modifierNumber;
    // if the character dies, the modified stat resets to zero
    if (newStat < 0)
    {
        return 0;
    }
    // Happy path
    if (newStat <= maxStat)
    {
        return stat += modifierNumber;
    }
    // the character's stat cannot exceed the maximum stat
    return stat = maxStat;
}

bool Character::theCharacterCanContinue() {
    return getHp() > 0 && getMorale() > 0;
}

void Character::checkCharacterCondition(int stat, int maxStat, std::string warningMessage) {
    if (stat < (maxStat / 5) && stat > 0)
    {
        std::cout << "Vigyázz! " << warningMessage << std::endl;
    }
}

void Character::initiateFinalDeath() const {
    std::cout << "A karaktered tragikus hirtelenséggel... Nem tudja folytatni a játékot."
                << " Több szerencsét legközelebb" << std::endl;
}