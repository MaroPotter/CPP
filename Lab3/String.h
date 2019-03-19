//
// Created by marek on 17.03.2019.
//

#ifndef LAB3_STRING_H
#define LAB3_STRING_H
class String
{
    int textLength;
    char const*text;
public:
    String(char const*, int);
    String(const String &);
    ~String();
    String& operator= (const String&);
    void print();

};
#endif //LAB3_STRING_H
