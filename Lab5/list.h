//
// Created by marek on 09.04.2019.
//

#ifndef LAB5_LIST_H
#define LAB5_LIST_H

#include <cstddef>
#include "oldmain.h"


class List {
public: //domyślnie generowane metody (4 z 6)
    List() : numberOfElements(0), head(nullptr) {}   //konstruktor domyślny
    List(const List &);         //konstruktor kopiujący
    List(List &&list2Move) noexcept;     //konstruktor przenoszący
    ~List();                    //destruktor

//metody do obsługi listy:

    Object *at(size_t index);

    Object *operator[](size_t index);


    void push_back(Object *newObject);

    List &operator+=(Object *newObject);

    Object *pop_back();

    auto size() const {
        return numberOfElements;
    }

private:
    struct Node {
        Object *obj;
        Node *next;

        Node(Object *obj = nullptr) : obj(obj), next(nullptr) {}

        Node(const Node &) = delete;

        ~Node();
    };

    Node *at_impl(size_t index);

    size_t numberOfElements;

    Node *head;

};

#endif //LAB5_LIST_H
