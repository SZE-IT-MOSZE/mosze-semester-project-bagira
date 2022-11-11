#include <string>
#include <vector>
#include <iostream>

#include "Page.h"
#include "Option.h"

Page::Page(int id, std::string question, std::vector<Option> options) : id(id), question(question), options(options) {}

int Page::getOptionSize() const {
    return options.size();
}

void Page::showPage() const {
    std::cout << question << std::endl;
    for(int i=0; i < options.size(); ++i){
        std::cout << i+1 << " - "<< options[i].getAnswer() << std::endl;
    }
}