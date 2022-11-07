#include "Page.h"
#include <unordered_map>

class Game{
    const std::unordered_map<int,Page> pages;

    public:

    Game(std::unordered_map<int,Page> pages):pages(pages){}

    Game(std::string path){
        //TODO read from file
    }

    void run(){
        size_t i=1;
        while(i!=0){
            pages.at(i).show();
            size_t j=i;
            i=pages.at(i).next();
            if(i==-1){
                std::cout<<"Ilyen opció nem létezik, kérem válasszon újra."<<std::endl;
                i=j;
            }
        }
        pages.at(0).show();
    }
};