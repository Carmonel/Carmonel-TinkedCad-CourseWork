#include "newStringParsing.h"
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(32, 16, 2);
String input;
Serial Serial;
lcd lcd;

bool isNumber(char ch){
    return ((ch >= '0') && (ch <= '9'));
}

bool checkIntString(String str){
    for (int i = 0; i < str.length(); i++){
        if ((i == 0) && (str.charAt(i) == '-')) continue;
        if (!isNumber(str.charAt(i))){
            Serial.print("\nString '" + str + "' have illegal char.");
            return false;
        }
    }
    return true;
}

class Num{
private:
    long value;
    short start, end;
    bool negative;
public:
    Num(short start){
        this->start = start;
        Serial.print("\nStart = ");
        Serial.print(start);
    }
    void setEnd(short endInput){
        this->end = endInput;
        Serial.print("\nEnd = ");
        Serial.print(end);
    }
    // Возвращает false, если число невозможно построить
    bool makeValue(){
        String str = input.substring(start, end);
        if (!checkIntString(str)) return false;
        value = str.toInt();

        Serial.print("\n-> num = '");
        Serial.print(str);
        Serial.print("' = ");
        Serial.print(value);
        return true;
    }
    long returnValue() const{
        return value;
    }
};

// 0 - |, 1 - &, 2 - !, 3 - +, 4 - -, 5 - *, 6 - /, 7 - mod, 8 - nod, 9 - nok
class Operator{
private:
    short value;
    String str;
    short start, end;
public:
    Operator(short start){
        this->start = start;
        Serial.print("\nStart = ");
        Serial.print(start);
    }
    void setEnd(short endInput){
        this->end = endInput;
        Serial.print("\nEnd = ");
        Serial.print(end);
    }
    // Возвращает false, если оператор невозможно построить
    bool makeValue(){
        String strTmp = input.substring(start, end);
        short opIt = 0;
        while (strTmp.charAt(opIt) != ' ') opIt++;
        str = strTmp.substring(0, opIt);
        Serial.print("\n-> op = '");
        Serial.print(str);
        Serial.print("'");

        if (str == "|"){
            value = 0;
            return true;
        }
        if (str == "&"){
            value = 1;
            return true;
        }
        if (str == "!"){
            value = 2;
            return true;
        }
        if (str == "+"){
            value = 3;
            return true;
        }
        if (str == "-"){
            value = 4;
            return true;
        }
        if (str == "*"){
            value = 5;
            return true;
        }
        if (str == "/"){
            value = 6;
            return true;
        }
        if (str == "mod"){
            value = 7;
            return true;
        }
        if (str == "nod"){
            value = 8;
            return true;
        }
        if (str == "nok"){
            value = 9;
            return true;
        }
        return false;
    }
    short returnOpValue() const{
        return value;
    }
};

long nod(long num1, long num2){
    long div;
    // если числа равны, НОД найден
    if (num1 == num2) return num1;
    // Находим разность чисел
    int d = (int)(num1 - num2);
    // Если разность отрицательная,
    if (num1 - num2 < 0)
    {
        d = -d;     // меняем знак
        div = nod(num1, d); // вызываем функцию NOD() для двух наименьших чисел
    }
    else      // если разность n1-n2 положительная
    {
        div = nod(num2, d); // вызываем функцию NOD() для двух наименьших чисел
    }
    return div;
}
long nok(long num1, long num2){
    return num1*num2 / nod(num1, num2);
}



void setup()
{
    Serial.begin(9600);
    Serial.println("Send me a calculation");
    Serial.println("E.G.  : 2+3");
    Serial.println();

    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
}

void loop(){
    while (Serial.available() > 0){
        lcd.clear();
        input = Serial.readString();
        Serial.println("Scanned string: '" + input + "'");
        short i = 0;

        //// Работа над первым числом
        // Поиск начала цифр первого числа, запоминание start
        while (input.charAt(i) == ' '){
            i++;
        }
        Num num1(i);
        // Поиск конца цифр первого числа, запоминание end
        if (input.charAt(i) == '-') i++;
        while (isNumber(input.charAt(i))) i++;
        num1.setEnd(i);
        // Формирование первого числа
        if (!num1.makeValue()) goto exit;


        //// Работа над оператором
        // Поиск начала оператора, запоминание opStart
        while (input.charAt(i) == ' '){
            i++;
        }
        Operator op(i);
        // Поиск конца оператора, запоминание opEnd
        while (!isNumber(input.charAt(i))){
            i++;
        }
        op.setEnd(i);
        // Формирование оператора
        if (!op.makeValue()) goto exit;




        //// Работа над вторым числом
        // Поиск начала цифр первого числа (не требуется), запоминание start
        if (input.charAt(i-1) == '-') i--;
        Num num2(i);
        // Поиск конца цифр первого числа, запоминание end
        if (input.charAt(i) == '-') i++;
        while (isNumber(input.charAt(i))) i++;
        num2.setEnd(i);
        // Формирование второго числа
        if (!num2.makeValue()) goto exit;




        //// Разветвление на операторы
        long result;
        switch (op.returnOpValue()){
            case 0:
                Serial.print("\nScanned operation '|'");
                result = num1.returnValue() | num2.returnValue();
                break;
            case 1:
                Serial.print("\nScanned operation '&'");
                result = num1.returnValue() & num2.returnValue();
                break;
            case 2:
                Serial.print("\nScanned operation '!'");
                result = !num1.returnValue();
                break;
            case 3:
                Serial.print("\nScanned operation '+'");
                result = num1.returnValue() + num2.returnValue();
                break;
            case 4:
                Serial.print("\nScanned operation '-'");
                result = num1.returnValue() - num2.returnValue();
                break;
            case 5:
                Serial.print("\nScanned operation '*'");
                result = num1.returnValue() * num2.returnValue();
                break;
            case 6:
                Serial.print("\nScanned operation '/'");
                result = num1.returnValue() / num2.returnValue();
                break;
            case 7:
                Serial.print("\nScanned operation 'mod'");
                result = num1.returnValue() % num2.returnValue();
                break;
            case 8:
                Serial.print("\nScanned operation 'nod'");
                result = nod(num1.returnValue(), num2.returnValue());
                break;
            case 9:
                Serial.print("\nScanned operation 'nok'");
                result = nok(num1.returnValue(), num2.returnValue());
                break;
        }

        Serial.print("\nResult: ");
        Serial.print(result);
        Serial.print("\n\n");
        lcd.print(result);
    }
    exit:;
}