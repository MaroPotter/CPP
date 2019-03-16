#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Item {
    int value;
    string description;
    string bonusType;

    Item() {
        value = 1;
        description = "0 item";
        bonusType = "0 bonus";
    }

    Item(int value, string description, string bonusType) {
        this->value = value;
        this->description = description;
        this->bonusType = bonusType;
    }

    Item(int value, char description[], char bonusType[]) {
        this->value = value;
        this->description = description;
        this->bonusType = bonusType;
    }

    void print(string separator) {
        cout << value << separator << description << separator << bonusType << endl;
    }
};

class Equipment {
private:
    int maxSize;
    Item *tab;
public:
    int realSize;

    Equipment(int);

    ~Equipment();

    void add(Item);

    void print(string);

    void write(string);

    void read();
};

Equipment::Equipment(int number) {
    maxSize = number;
    realSize = 0;
    tab = new Item[maxSize];
}

Equipment::~Equipment() {
    delete[] tab;
}

void Equipment::add(Item item) {
    if (realSize < maxSize) {
        tab[realSize] = item;
        realSize++;
    }
}

void Equipment::print(string separator) {
    for (int i = 0; i < realSize; i++) {
        cout << i + 1 << "." << separator;
        tab[i].print(separator);
    }
}

void Equipment::write(string separator) {
    ofstream file;
    file.open("file.txt", ios_base::app);
    if (!file.is_open()) {
        cout << "Error, cos sie spierdolilo" << endl;
        return;
    }
    for (int i = 0; i < realSize; i++) {
        file << i + 1 << "." << separator << tab[i].value << separator << tab[i].description << separator
             << tab[i].bonusType << endl;
    }
    file.close();
}

// najprostsza wersja, w której elementy danego Itemu są w 1 linii
// i numeracja jest nie taka jak powinna być XD


/* void Equipment::read() {

     ifstream file;
     file.open("odczyt.txt");
     if (!file.good())
         cout << "Error! Nie udalo sie otworzyc pliku!" << endl;
     string line;
     int i = 0;
     while (getline(file, line)) {
         cout << i << "." << "   " << line << endl;
         i++;
     }
     file.close();
 } */


// wersja, w której elementy danego Itemu są w 1 linii
// i każdy element to pojedynczy wyraz (więc przy opisie trochę słabo)


/* void Equipment::read() {
    ifstream file;
    file.open("odczyt.txt");
    if(!file.good())
        cout<< "Error! Nie udalo sie otworzyc pliku! "<<endl;
    string line;
    while (1) {
        int value_read;
        string description_read;
        string bonusType_read;
        file >> value_read >> description_read >> bonusType_read;
        if (!file.fail()) {
            Item a(value_read, description_read, bonusType_read);
            realSize++;
            for (int i = realSize - 1; i < realSize; i++) {
                tab[i] = a;
            }
        } else {
            break;
        }
    }
    file.close();
} */


// wersja dla pliku z kazdym elementem w innej linii
// elementy mogą być wielowyrazowe (oprócz value, bo w zamyśle to tylko liczba naturalna)


/* void Equipment::read() {
    ifstream file;
    file.open("reading.txt");
    if (!file.good())
        cout << "Error! Nie udalo sie otworzyc pliku!" << endl;
    while (!file.eof()) {
        cout << "Pozycja wskaznika w pliku 0: " << file.tellg() << endl;
        int value_read;
        char tmp[1];
        char description_read[100];
        char bonusType_read[100];
        file >> value_read;
        cout << value_read << endl;
        cout << "Pozycja wskaznika w pliku 1: " << file.tellg() << endl;
        file.getline(tmp, 1, '\n');
        file.getline(description_read, 100, '\n');
        cout << description_read << endl;
        cout << "Pozycja wskaznika w pliku 2: " << file.tellg() << endl;
        file.getline(bonusType_read, 100, '\n');
        cout << bonusType_read << endl;
        cout << "Pozycja wskaznika w pliku 3: " << file.tellg() << endl;
        Item a(value_read, description_read, bonusType_read);
        realSize++;
        for (int i = realSize - 1; i < realSize; i++) {
            cout << "Udalo sie" << endl;
            tab[i] = a;
        }
    }
    file.close();
} */


// wersja dla pliku z elementami danego Itemu w 1 linii,
// elementy są oddzielone znakiem tabulacji
// elementy typu string mogą być wielowyrazowe


void Equipment::read() {
    ifstream file;
    file.open("odczyt.txt");
    if (!file.good())
        cout << "Error! Nie udalo sie otworzyc pliku!" << endl;
    while (!file.eof()) {
        int value_read;
        char tmp[1];
        char description_read[100];
        char bonusType_read[100];
        file >> value_read;
        cout << value_read << endl;
        file.getline(tmp, 1, '\t');
        file.getline(description_read, 100, '\t');
        cout << description_read << endl;
        file.getline(bonusType_read, 100, '\n');
        cout << bonusType_read << endl;
        Item a(value_read, description_read, bonusType_read);
        realSize++;
        for (int i = realSize - 1; i < realSize; i++) {
            tab[i] = a;
            cout << "Udalo sie" << endl;
        }
    }
    file.close();
}


int main() {
    cout << "Wpisz maxSize: " << endl;
    int n;
    string s = " | ";
    cin >> n;
    Item i1;
    Item i2(2, "sword", "AD_damage");
    Item i3(3, "shield", "armor");
    Equipment e(n);
    cout << "RealSize przed dodaniem itemow: " << e.realSize << endl;
    e.add(i1);
    e.add(i2);
    e.add(i3);
    cout << "Aktualny realSize: " << e.realSize << endl;
    e.read();
    e.write(s);
    cout << "Wszystkie itemy: " << endl;
    e.print(s);
    return 0;
}