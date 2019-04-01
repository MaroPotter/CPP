//
// Created by marek on 01.04.2019.
//

#ifndef LAB5_OLDMAIN_H
#define LAB5_OLDMAIN_H
#include <iostream>

using namespace std;

class Object {
public:
    Object() = default;
    Object(const Object&) = default;
    virtual ~Object();
    virtual operator string() const
    {
        return toString();
    }
    virtual string toString() const = 0;

    virtual Object *clone() const = 0;

    virtual string whatAmI() const = 0;

    virtual Object& operator+=(const Object&) = 0;
    virtual Object& append(const Object& obj)
    {
        *this += obj;
        return *this;
    }
protected:
    bool isTheSameType(const Object& obj) const {
        return obj.whatAmI() == whatAmI();
    }
};
Object::~Object() =  default; //zdefiniowany tutaj aby uniknac warninga

class DoubleObject : public Object {
    double value;
public:
    explicit DoubleObject(double value) : value(value) {}

    string whatAmI() const override {
        return "DoubleObject";
    }

    string toString() const override {
        return whatAmI() + "(" + to_string(value) + ")";
    }

    Object *clone() const override {
        return new DoubleObject(*this);
    }

    Object& operator+=(const Object& obj) override {
        if(isTheSameType(obj)) {
            value += dynamic_cast<const DoubleObject&>(obj).value;
        }
        else {
            cerr<<"Different type, expected" << whatAmI() << ", received: "<<obj.whatAmI() << endl;
        }
        return *this;
    }
    auto getValue() const
    {
        return value;
    }
};
class StringObject : public Object{
    string text;
public:
    StringObject() = default;
    StringObject(const string &text) : text(text) {}
    StringObject(const StringObject&) = default;
    ~StringObject() override = default;
    string whatAmI() const override
    {
        return text;
    }
    string toString() const override
    {
        return text;
    }
    Object* clone() const override
    {
        return new StringObject(*this);
    }
    Object& operator+=(const Object& obj) override
    {
        if(isTheSameType(obj)) {
            auto conversion = dynamic_cast<const StringObject *>(&obj);
            this->text += conversion->text;
        }
        else
        {
            cerr<<"Different type, expected:"<<whatAmI()<<", received: "<<obj.whatAmI()<<endl;
        }
        return *this;
    }
};
#endif //LAB5_OLDMAIN_H
