//
// Created by marek on 17.03.2019.
//

#ifndef LAB3_STRING_H
#define LAB3_STRING_H

#include <cstring>

class String
{
    char* text;
    size_t tabSize, textSize;
    void IsEnough (size_t); // make sure buffer is enough to add more characters which number is given in the argument
public:
    String();
    String(const char*);
    String(const String &);
    ~String();
    void print();
    String& operator= (const String&);
    String& operator= (const char*);
    size_t getSize() const;


};
#endif //LAB3_STRING_H
