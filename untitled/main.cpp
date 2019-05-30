#include <iostream>

using namespace std;

class Skaner {
protected:
    int rozdzielczosc;
    int szybkosc;
public:
    Skaner() : rozdzielczosc(1), szybkosc(1) {}

    Skaner(int, int);

    void zmien();

    friend ostream &operator<<(ostream &e, const Skaner &s);
};

void Skaner::zmien() {
    int a;
    cin >> a;
    rozdzielczosc += a;
    szybkosc += a;
}

Skaner::Skaner(int r, int s)
        : rozdzielczosc(r), szybkosc(s) {}

ostream &operator<<(ostream &e, const Skaner &s) {
    e << s.rozdzielczosc << " " << s.szybkosc;
    return e;
}

class Drukarka {
protected:
    int rozdzielczosc;
public:
    void zmien();

    Drukarka() = default;

    Drukarka(int b) : rozdzielczosc(b) {}

    friend ostream &operator<<(ostream &e, const Drukarka &d) {
        e << d.rozdzielczosc;
        return e;
    }
};

void Drukarka::zmien() {
    int a;
    cin >> a;
    rozdzielczosc += a;
}

class Kopiarka : public Skaner, public Drukarka {
public:
    Kopiarka() = default;

    void zmien();

    friend ostream &operator<<(ostream &e, const Kopiarka &k) {
        e << k.Drukarka::rozdzielczosc << " " << k.Skaner::rozdzielczosc << " " << k.szybkosc;
        return e;
    }
};

void Kopiarka::zmien() {
    int a;
    cin >> a;
    Skaner::rozdzielczosc += a;
    Skaner::szybkosc += a;
    Drukarka::rozdzielczosc += a;
}


int main() {
    cout << "Hello, World!" << std::endl;
    Skaner s(2, 2);
    s.zmien();
    cout << s << endl;
    Drukarka d(2);
    d.zmien();
    Kopiarka k;
    k.zmien();
    cout << k << endl;


    return 0;
}