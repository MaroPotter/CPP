#include <iostream>
#include "String.h"

using namespace std;

int main() {
    char const *t1 = "cos dla a";
    char const *t2 = "cos dla b";
    String a(t1, 10);
    String b(t2, 10);
    a.print();
    b.print();
    String c(b);
    b = a;
    cout << "I co teraz?" << endl;
    b.print();
    c.print();

    return 0;
}