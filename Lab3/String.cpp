//
// Created by marek on 17.03.2019.
//
#include "String.h"
#include <iostream>

using namespace std;

String::String(char const *_text, int _textLength)
        : text(_text), textLength(_textLength) {}

String::String(const String &_string)
        : text(_string.text), textLength(_string.textLength) {}

String::~String() {
    delete[] text;
}

void String::print() {
    cout << text << endl;
}

String &String::operator=(const String &s) {
    cout << "przypisuje" << endl;
    if (this == &s) return *this;
    text = s.text;
    return *this;
}


