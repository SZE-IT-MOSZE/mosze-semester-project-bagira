#include <fstream>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <string>

#include "Json.h"

#include "User.h"
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
        User* user = new User();
        std::cout << "Kérlek add meg a felhasználóneved: ";
        std::cin >> username;
        user->setName(username);
        std::cout <<std::endl;
        int selected = 0;  
        int j = 0;      
        for(int i = 0; i < pages.size(); i++) {
            pages.at(i).showPage();
            while(true) {
                if (std::cin >> selected && (selected <= pages.at(i).getOptionSize() && selected > 0)) {
                    if(selected == 2 || selected == 3){
                        i+=2;
                    }
                    break; 
                } else {
                    std::cout << "Ilyen opció nem létezik, kérem válasszon újra." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
        }

        /*int pageIndex = pages.at(1).getPageId();
        while(pageIndex > 0 && pageIndex  < pages.size()) {
            Page currentPage = pages.at(pageIndex);
            currentPage.showPage();
            while (std::cin >> selected && selected < 1 && selected > pages.size()) {
                std::cout << "Ilyen opció nem létezik, kérem válasszon újra." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            pageIndex = currentPage.getToPageId(selected);
        }*/

        std::cout<<"Vége a játéknak!"<<std::endl;
        delete user;
    }