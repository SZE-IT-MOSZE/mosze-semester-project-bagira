#include "include/Game.h"
#include <iostream>

int main(int argc,char** argv){
    std::unordered_map<int,Page> pages;
    Page p1 = Page(0,"Meghaltál! Vége a játéknak...");
    Page p2 = Page(1, "Melyik a kedvenc gyümid?", {Option(2, "alma"), Option(3, "körte")});
    Page p3 = Page(2, "Szereted az almát", {Option(0, "tovább")});
    Page p4 = Page(3, "Szereted a körtét", {Option(0, "tovább")});
    pages.insert({0,p1});
    pages.insert({1,p2});
    pages.insert({2,p3});
    pages.insert({3,p4});
    Game game(pages);
    game.run();
}