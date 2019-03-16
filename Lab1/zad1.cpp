#include <iostream>
#include <cmath>
using namespace std;

class Array {
private:
    int *array;
    int arrayLength;


    int *_createArray();

    void check(int);

public:

    Array(int);

    ~Array();

    int get(int);

    void fill(int);

    void assign(const int[], int);

    void set(int, int);

    int *front();

    int *back();

    int size();

    Array *clone();
};

int *Array::_createArray() {
    return new int[arrayLength];
}

int Array::get(int index) {
    check(index);
    return array[index];
}

void Array::fill(int value) {
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = value;
    }
}

void Array::assign(const int tab[], int tabSize) {
    for (int i = 0; i < tabSize; ++i) {
        array[i] = tab[i];
    }
}

void Array::set(int index, int value) {
    check(index);
    array[index] = value;
}

Array::Array(int arrayLength) {
    this->arrayLength = arrayLength;
    array = _createArray();
}

Array::~Array() {
    delete[] array;
}

int *Array::front() {
    int *first = &array[0];
    return first;
}

int *Array::back() {
    int *back = &array[size() - 1];
    return back;
}

Array *Array::clone() {
    Array *array2 = new Array(arrayLength);
    for (int i = 0; i < arrayLength; i++) {
        array2->array[i] = this->array[i];
    }
    return array2;
}

int Array::size() {
    return arrayLength;
}

void Array::check(int index) {
    if (index < 0 || index >= arrayLength) {
        cout << "Blad!" << endl;
    }
}

int main() {
    int n;
    int tablica[10];
    for (int i = 0; i < 10; ++i) {
        tablica[i] = i;
    }
    cin >> n;
    Array *a = new Array(n);
    a->set(0, 15);
    a->set(1, 20);
    a->set(2, 25);
    a->set(3, 30);
    a->set(4, 35);
    cout << a->get(0) << ' ';
    cout << a->get(1) << ' ';
    cout << a->get(2) << ' ';
    cout << a->get(3) << ' ';
    cout << a->get(4) << endl;
    /*cout << "array2: " << endl;
    cout << a->clone()->get(0) << ' ';
    cout << a->clone()->get(1) << endl;
    cout << "Znowu array a: " << endl;
    cout << a->size() << endl;
    cout << *a->front() << endl;
    cout << *a->back() << endl;
     a->assign(tablica, 10);
    for (int i = 0; i < a->arrayLength; ++i) {
        cout << a->get(i) << ' ';
    } */
    cout << a->size() << endl;
    cout<<isnan(sqrt(-1))<<endl;
    return 0;
}