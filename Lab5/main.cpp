//
// Created by marek on 09.04.2019.
//
#include <iostream>

using namespace std;

#include "oldmain.h"
#include "list.h"


int main() {
    auto *b = new DoubleObject(3.0);
    auto *c = new DoubleObject(4.0);
    auto *d = new DoubleObject(5.0);
    List l;
    l.push_back(b);
    l.push_back(c);
    l.push_back(d);
    cout<<l.at(2)<<endl;
    cout<<l[2]<<endl;
    return 0;
}

