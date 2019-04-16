//
// Created by marek on 09.04.2019.
//

#include "list.h"
#include "oldmain.h"
#include <iostream>
#include <typeinfo>

using namespace std;

List::List(const List &list_copy) :
        numberOfElements(list_copy.numberOfElements) {
    for (Node *node = list_copy.head; node; node = node->next) {
        if (node->obj) {
            auto objectCopy = node->obj->clone();
            push_back(objectCopy);
        }
    }
}

List::List(List &&list2Move) noexcept :
        numberOfElements(move(list2Move.numberOfElements)),
        head(move(list2Move.head)) {
    list2Move.head = nullptr;
    list2Move.numberOfElements = 0;
}

List::~List() {
    while (numberOfElements > 0) {
        pop_back();
        cout << numberOfElements << endl;
    }
}

Object *List::at(size_t index)
{
    if(index >= numberOfElements)
        return nullptr;
    Node *node = head;
    for(decltype(index) i = 0; node && i!=index; ++i, node=node->next) {}
    return node->obj;
}
Object *List::operator[](size_t index)
{
    return this->at(index);
}
void List::push_back(Object *newObject) {
    Node *newNode = new Node(newObject);
    if(head)
    {
        at_impl(numberOfElements-1)->next=newNode;
    }
    else
    {
        head=newNode;
    }

    numberOfElements++;
}

Object *List::pop_back() {
    if (numberOfElements <= 0) {
        return nullptr;
    }
    Node *lastNode = head;
    while (lastNode->next) {
        lastNode = lastNode->next;
    }
    Object *valueOfLastNode = lastNode->obj;
    lastNode->obj = nullptr;
    delete lastNode;
    if (numberOfElements == 1) {
        head = nullptr;
    } else {
        Node *nodeBeforeLast = head;
        while (nodeBeforeLast->next->next) {
            nodeBeforeLast = nodeBeforeLast->next;
        }
        nodeBeforeLast->next = nullptr;
    }

    numberOfElements--;
    return valueOfLastNode;
}
List::Node *List::at_impl(size_t index)
{
    if(index<numberOfElements)
    {
        Node *node = head;
        for(decltype(index) i=0; node && i!=index; ++i, node=node->next)
        {
        }
        return node;
    }
    else
    {
        return nullptr;
    }
}

List::Node::~Node() {
    delete obj;
    obj = nullptr;
    next = nullptr;
}

