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
    setHp(updateStat(getHp(), optionData.getHp(), MAX_HP));
    setMorale(updateStat(getMorale(), optionData.getMorale(), MAX_MORALE));
}

int Character::updateStat(int stat, int modifierNumber, int maxAmount) {
    if (stat + modifierNumber <= maxAmount)
    {
        return stat += modifierNumber;
    }
    return stat = maxAmount;
}