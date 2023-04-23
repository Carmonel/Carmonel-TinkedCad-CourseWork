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
    void print(long value);
};

class String{
private:
    std::string string;

public:
    void setString(std::string str);
    std::string returnString();
    short length();
    long toInt();
    char charAt(short index);
    char charAt(int index);
    String substring(short start, short end);
    bool operator==(String cmp){
        return string == cmp.returnString();
    }
    bool operator==(const char* cmp){
        return string == cmp;
    }
};

class Serial{
public:
    void begin(int value);
    String readString();
    void println();
    void println(string str);
    int available();
    void print(string str);
    void print(String str);
    void print(int value);
    void print(long value);
};

#endif //TINKERCAD_COURSEWORK_NEWSTRINGPARSING_H
