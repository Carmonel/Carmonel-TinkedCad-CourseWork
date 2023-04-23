#include "newStringParsing.h"
#include "string"
#include "iostream"

char String::charAt(short index){
    return string[index];
}
short String::length(){
    return string.length();
}
String String::substring(String str, short start, short end){

}
std::string String::returnString(){
    return string;
}
long String::toInt() {
    return stol(string);
}

void Serial::print(string str){
    cout << str;
}

void Serial::print(int value) {
    cout << value;
}

void Serial::print(String str) {
    cout << str.returnString();
}

void Serial::begin() {
    cout << "Serial::begin();" << endl;
}

int Serial::available() {
    cout << "Serial::available();" << endl;
    return 1;
}

void Serial::println(string str) {
    cout << "\n" << str;
}

void parseInt(string input){
    int i = 0;
}

void lcd::setCursor(short a, short b) {
    cout << "lcd::setCursor(" << a << ", " << b << ");" << endl;
}

void lcd::backlight() {
    cout << "lcd::backlight();" << endl;
}

void lcd::clear() {
    cout << "lcd::clear();" << endl;
}

void lcd::init() {
    cout << "lcd::init();" << endl;
}

void lcd::print(int value) {
    cout << "lcd::print(); -> " << value;
}
