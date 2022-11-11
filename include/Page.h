#pragma once

#include <string>
#include <vector>

#include "Option.h"

class Page{
    const int id;
    const std::string question;
    std::vector<Option> options;

public:

    Page(int id, std::string question, std::vector<Option> options);

    int getOptionSize() const;

    void showPage() const;
};