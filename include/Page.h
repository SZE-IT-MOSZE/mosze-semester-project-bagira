/**
 * @file Page.h
 * @author Bagira csapat
 * @brief Page class
 * @version 1.0
 * @date 2022-11-15
 */
#pragma once

#include <string>
#include <vector>

#include "Option.h"

/**
 * @brief Represents a page.
 * 
 * This class is responsible for displaying the questions and the options for the user
 * 
 */
class Page{
    const int id; ///< The id of the page
    const std::string question; ///< Text display of the question
    std::vector<Option> options; ///< A vector that contains all the options for the question

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
 * @brief Get the number of options
 * 
 * @return int 
 */
    int getOptionSize() const;
/**
 * @brief 
 * 
 * Function that shows the page (question, options).
 * 
 */
    void showPage() const;

/**
 * @brief Get the Id of the page
 * 
 * @return int 
 */
    int getPageId() const;

/**
 * @brief Get the id to the next page
 * 
 * @param selectedOption 
 * @return int 
 */
    int getToPageId(int selectedOption) const;
};