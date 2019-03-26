//
// Created by marek on 17.03.2019.
//
#include "String.h"
#include <iostream>
using namespace std;

void String::IsEnough(size_t neededNumberOfCharacters) {
    if(textSize + neededNumberOfCharacters > tabSize )
    {
        char* newText = new char[neededNumberOfCharacters];
        if(text)
        {
            strcpy(newText, text);
        }
        delete [] text;
        text = newText;
        tabSize = neededNumberOfCharacters;
    }
}

String::String()
        : text(nullptr), tabSize(0), textSize(0) {}

String::String(const char *text) : String() {
    if (text) {
        textSize = strlen(text);
        IsEnough(textSize + 1);
        strcpy(this->text, text);
    }
}

String::String(const String &_string)
        : text(_string.text) {}

String::~String() {
    delete[] text;
}

void String::print() {
    cout << text << endl;
}

String& String:: operator=(const String & str)
{
    if(this != &str)
    {
        IsEnough(str.textSize+1);

        strcpy(text, str.text);
        textSize = str.textSize;
    }

    return *this;
}
String& String:: operator=(const char* str)
{
    (*this) = String(str);
    return *this;
}
size_t String::getSize() const {
    return textSize;
}



