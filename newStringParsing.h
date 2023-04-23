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
    void print(int value);
};

class String{
private:
    std::string string;

public:
    std::string returnString();
    short length();
    long toInt();
    char charAt(short index);
    String substring(String str, short start, short end);
    bool operator=(String cmp){
        return string == cmp.returnString();
    }
};

class Serial{
public:
    void begin();
    void println(string str);
    int available();
    void print(string str);
    void print(String str);
    void print(int value);
};

#endif //TINKERCAD_COURSEWORK_NEWSTRINGPARSING_H
