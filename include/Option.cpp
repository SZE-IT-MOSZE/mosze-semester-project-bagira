#include <string>

#include "Option.h"

Option::Option(std::string answer, int hp, int morale, int toPage) : answer(answer), hp(hp), morale(morale), toPage(toPage) {}
std::string Option::getAnswer() const {
    if(answer == "") {
        return "Valami";
    }
    return answer;
}
