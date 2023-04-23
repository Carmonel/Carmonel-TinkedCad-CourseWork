//
// Created by Ярослав on 22.04.2023.
//

#ifndef TINKERCAD_COURSEWORK_NEWSTRINGPARSING_H
#define TINKERCAD_COURSEWORK_NEWSTRINGPARSING_H
#include "string"

using namespace std;

class lcd{
public:
    void init();
    void clear();
    void backlight();
    void setCursor(short a, short b);
};

class Serial{
public:
    void print(string str);
};

class String{
private:
    std::string string;

public:
    std::string returnString();
    short length();
    char charAt(short index);
    String substring(String str, short start, short end);
    bool operator=(String cmp){
        return string == cmp.returnString();
    }
};


#endif //TINKERCAD_COURSEWORK_NEWSTRINGPARSING_H
