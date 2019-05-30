#include <iostream>
#include "rozwiazanieZad1singleton.cpp"
using namespace std;
int main() {

    //Zad1 testing

    Message1 &m1 = Message1::instance();
   /* Message1 m2 = Message1::instance();   the commented section should not compile
    Message1 m3 = m1;
    Message1 m4 = std::move(m1);
    Message1 m5; */
    Message1::instance().log("Przyszłość zaczyna...");
    m1.log("..się dzisiaj, nie jutro");
    Message1* m6 = &Message1::instance();
    m6 -> log("Bez pracy nie ma kołaczy");
    Message1::instance().log("Nauka to potęgi..");

    return 0;
}