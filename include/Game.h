/**
 * @file Game.h
 * @author Bagira csapat
 * @brief Game class
 * @version 1.0
 * @date 2022-11-10
 */
#pragma once

#include <string>
#include <vector>

#include "Page.h"

/**
 * @brief Game class
 * 
 * This class is responsible for reading from file and for running the game
 * 
 */
class Game{
    std::vector<Page> pages; ///< A vector that contains all the pages

public:
    /**
     * @brief Construct a new Game object
     * 
     * @param filename 
     */
    Game(std::string& filename);
    /**
     * @brief 
     * 
     * Function which is responsible for reading the story from file 
     * 
     * @param filename The name of the file to read from
     * @return std::vector<Page> 
     */
    static std::vector<Page> loadJson(std::string& filename);
    /**
     * @brief 
     * 
     * This function is responsible for running the game
     * 
     */
    void run();
};