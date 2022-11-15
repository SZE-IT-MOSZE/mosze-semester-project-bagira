/**
 * @file Page.h
 * @author Bagira csapat
 * @brief 
 * @version 0.1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <string>
#include <vector>

#include "Option.h"

/**
 * @brief Represents a page.
 * 
 * 
 */
class Page{
    const int id;
    const std::string question;
    std::vector<Option> options;

public:
/**
 * @brief Construct a new Page object
 * 
 * @param id 
 * @param question 
 * @param options 
 */
    Page(int id, std::string question, std::vector<Option> options);
/**
 * @brief Get the Option Size object
 * 
 * @return int 
 */
    int getOptionSize() const;
/**
 * @brief 
 * 
 */
    void showPage() const;
};