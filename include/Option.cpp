#include <string>

#include "Option.h"

Option::Option(std::string answer, int hp, int morale) : answer(answer), hp(hp), morale(morale) {}

std::string Option::getAnswer() const {
    return answer;
}