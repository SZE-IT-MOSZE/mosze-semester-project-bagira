#include "Option.h"
#include <vector>
#include <stdexcept>

class Page{
    const int index;
    const std::string text;
    std::vector<Option> options;

    int readSelection() const {
        int number = 0;
        std::cin>>number;
        return number;
        
    }
    public:

    void show() const{
        std::cout<<getText()<<std::endl;
        for(size_t i=0;i<options.size();++i){
            std::cout<<i+1<<" - "<<options[i].getText()<<std::endl;
        }
    }

    int getIndex() const {
        return index;
    }
    std::string getText() const {
        return text;
    }

    int next() const {
        std::cout<<"?"<<std::endl;
        try{
            return options.at(readSelection()-1).getPage();
        }catch(const std::out_of_range& e){
            std::cout<<'\n';
            return -1;
        }
    }


    Page(int index,std::string text,std::vector<Option> options):index(index),text(text),options(options){}

    Page(int index,std::string text):index(index),text(text){}
};