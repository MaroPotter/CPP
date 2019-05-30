#include <iostream>
#include <cstdio>

class Message1
{
    int counter = 0;

    Message1() { }
    Message1(const Message1&) = delete;
    Message1(Message1&&) = delete;
public:
    static Message1& instance()
    {
        static Message1 m;
        return m;
    }
    void log(const char* text) {
        std::cout << counter++ << ": " << text << std::endl;
    }
};

class Message2
{
    static int counter;
    static Message2 m2;

    Message2() = default;
    Message2(const Message2&) = delete;
    Message2(Message2&&) = delete;
public:
    static Message2& instance()
    {
        return m2;
    }
    void log(const char* text) {
        std::cout << counter++ << ": " << text << std::endl;
    }
};
int Message2::counter = 0;
Message2 Message2::m2;

class Message3
{
    Message3() = default;
    Message3(const Message3&) = delete;
    Message3(Message3&&) = delete;
public:
    static Message3& instance()
    {
        static Message3 m;
        return m;
    }
    void log(const char* text) {
        static int counter;
        std::cout << counter++ << ": " << text << std::endl;
    }
};

// alternatywnie mozna zrobic tzw. double checked singleton -ale to juz bardziej zaanwansowana zabawa
