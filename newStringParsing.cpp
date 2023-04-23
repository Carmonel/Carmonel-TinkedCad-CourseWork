#include "newStringParsing.h"
#include "string"
#include "iostream"

char String::charAt(short index){
    return string[index];
}
short String::length(){
    return string.length();
}
String String::substring(short start, short end){
    String result;
    std::string str(this->returnString(), start, this->length()-end);
    result.setString(str);
    return result;
}
std::string String::returnString(){
    return string;
}
long String::toInt() {
    return stol(string);
}

void String::setString(std::string str) {
    void setString(std::string str){
        string = str;
    }
}

char String::charAt(int index) {
    return string[index];
}

void Serial::print(std::string str){
    cout << str;
}
void Serial::print(String str){
    cout << str.returnString();
}

void Serial::begin(int value) {
    cout << "Serial::begin();" << endl;
}

int Serial::available() {
    cout << "Serial::available();" << endl;
    return 1;
}

void Serial::println(string str) {
    cout << "\n" << str;
}

void Serial::println() {
    cout << endl;
}

String Serial::readString() {
    std::string tmp;
    cin >> tmp;
    String result;
    result.setString(tmp);
    return result;
}

void Serial::print(int value) {
    cout << value;
}
void Serial::print(long value) {
    cout << value;
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

void lcd::print(long value) {
    cout << "lcd::print(); -> " << value;
}
