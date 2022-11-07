#pragma once
#include<iostream>
#include<string.h>

class Option{
    const int page;
    const std::string text;
    public:

    Option(int page,std::string text):page(page),text(text){}

    std::string getText() const{
        return text;
    }

    int getPage() const {
        return page;
    }
    
};