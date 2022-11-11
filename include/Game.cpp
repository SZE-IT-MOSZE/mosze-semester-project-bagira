#include <fstream>
#include <unordered_map>
#include <iostream>
#include <sstream>

#include "json.hpp"

#include "Game.h"
#include "Page.h"
#include "Option.h"

Game::Game(std::string& filename) : pages(loadJson(filename)) {};

std::vector<Page> Game::loadJson(std::string& filename) {
    std::ifstream fJson(filename);
    std::stringstream buffer;
    buffer << fJson.rdbuf();

    auto json = nlohmann::json::parse(buffer.str());

    std::vector<Page> helper_pages;
    for (auto item : json["questions"])
    {
        int id = item["id"];
        std::string question = item["question"];
        std::vector<Option> options;
        for (auto opt : item["options"])
        {
            std::string answer = opt["answer"];
            int hp = opt["hp"];
            int morale = opt["morale"];
            
            Option option(answer, hp, morale);
            options.push_back(option);
        }
        Page page(id, question, options);
        helper_pages.push_back(page);
    }

    std::cout << "JSON fájl betöltve." << std::endl;
    return helper_pages;
}

    void Game::run() {
        int selected = 0;        
        for(int i = 0; i < pages.size(); i++) {
            pages.at(i).showPage();
            while(true) {
                if (std::cin >> selected && (selected <= pages.at(i).getOptionSize() && selected > 0)) {
                    break;
                } else {
                    std::cout << "Ilyen opció nem létezik, kérem válasszon újra." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }
    }