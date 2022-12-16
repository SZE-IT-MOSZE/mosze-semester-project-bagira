#include <fstream>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>

#include "Json.h"

#include "Character.h"
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
            int toPage = opt["toPage"];
            
            Option option(answer, hp, morale, toPage);
            options.push_back(option);
        }
        Page page(id, question, options);
        helper_pages.push_back(page);
    }

    std::cout << "JSON fájl betöltve." << std::endl;
    std::cout << "Figyelem! Minden állomásnál a kérdésekre a megadott válaszlehetőség sorszámának beírásával van lehetőség döntést hozni!" << std::endl;
    return helper_pages;
}

    void Game::run() {
        std::string username = "";
        Character user;
        std::cout << "Kérlek add meg a felhasználóneved: ";
        std::cin >> username;
        user.setName(username);
        std::cout <<std::endl;
        int selected = 0;
        int pageIndex = pages.at(0).getPageId();
        while(pageIndex > 0) {
            std::cin.clear();
            // if the page not found or below the first id, the story ends
            if (pageIndex < 1 || pageIndex > pages.size())
            {
                break;
            }
            // get our character's conditons
            user.getStatus();
            Page currentPage = pages.at(pageIndex-1);
            currentPage.showPage();
            std::cin >> selected;
            // if our choice is 0 or negative (or anything else than a number) the story ends
            if (selected <= 0)
            {
                break;
            }
            // check if our choice number is greater than the options we have
            while (selected  > pages.at(pageIndex-1).getOptionSize()) 
            {
                std::cout << "Ilyen opció nem létezik, kérem válasszon újra." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin >> selected;

            }
            user.updateCharacterStatus(currentPage.getOptions().at(selected-1));
            // if the character doesn't have enough stats, the story ends
            if (!user.theCharacterCanContinue())
            {
                user.initiateFinalDeath();
                user.getStatus();
                break;
            }
            // the story continues with the next page (unless the story ends)
            pageIndex = currentPage.getToPageId(selected-1);
        }

        std::cout<<"Vége a játéknak!"<<std::endl;
    }