/**
 * @file Game.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <string>
#include <vector>

#include "Page.h"

/**
 * @brief 
 * 
 */
class Game{
    std::vector<Page> pages;

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
     * @param filename 
     * @return std::vector<Page> 
     */
    static std::vector<Page> loadJson(std::string& filename);
    /**
     * @brief 
     * 
     */
    void run();
};