#include <iostream>
#include <cstring>
#include "../Lab5/list.h"
using namespace std;

template <typename typeto, typename typefrom>
typeto best_cast(typefrom& src) {
    return dynamic_cast<typeto&>(src);
}

template <typename typeto, typename typefrom>
typeto best_cast(typefrom* src) {
    if (auto* dst = dynamic_cast<typeto>(src)) {
        return dst;
    }
    else {
        throw bad_cast{};
    }
}

int main()
{
    List l;
    l.push_back(new DoubleObject(4));
    l.push_back(new DoubleObject(33));
    l.push_back(new StringObject("Crazy text"));
    l.push_back(new DoubleObject(4));


    /// rozpoznawanie typu przy pomocy polimorfizmu:
    DoubleObject tmpDoubleObject(4);
    for (decltype(l.size()) i=0; i<l.size(); ++i)
    {
        if (l[i]->whatAmI() == tmpDoubleObject.whatAmI())
        {
            auto& DoubleObjectTwo = static_cast<DoubleObject&>(*l[i]);
            cout << __LINE__ << ") --->>" << DoubleObjectTwo.getDoubleContent() << endl;
        }
    }
    /// rozpoznawanie typu przy pomocy typeid:
    for (decltype(l.size()) i=0; i<l.size(); ++i)
    {
        if (typeid (*l[i]) == typeid(DoubleObject&))
        {
            auto& DoubleObjectTwo = static_cast<DoubleObject&>(*l[i]);
            cout << __LINE__ << ")--->>" << DoubleObjectTwo.getDoubleContent() << "\t typeid.name: "
                 << typeid(l[i]).name() << endl;
        }
    }

    /// rozpoznawanie typu przy pomocy dynamic_cast dla wskaznikow:
    for (decltype(l.size()) i=0; i<l.size(); ++i)
    {
        if (auto* DoubleObject = dynamic_cast<DoubleObject*>(l[i]))
        {
            cout << __LINE__ << ")--->>" << DoubleObject->getDoubleContent() << endl;
        }
    }

    /// rozpoznawanie typu przy pomocy dynamic_cast dla referencji:
    for (decltype(l.size()) i=0; i<l.size(); ++i)
    {
        try
        {
            DoubleObject &DoubleObject = dynamic_cast<DoubleObject&>(*l[i]);
            cout << __LINE__ << ")--->>" << DoubleObject%2 << endl;
        }
        catch(const bad_cast& e)
        {
            cerr << __LINE__ << ") wyjatek: " << e.what() << " dla: " << l[i]->whatAmI() << endl;
        }
    }

    /// rozpoznawanie typu przy pomocy wlasnej wersji rzutowania:
    for (decltype(l.size()) i=0; i<l.size(); ++i)
    {
        try{
            auto* DoubleObjectThree = best_cast<DoubleObject*>(l[i]);
            cout << __LINE__ << ")--->>" << DoubleObjectThree->getDoubleContent() << endl;
        }
        catch(const std::bad_cast& b){
            cerr << __LINE__ << ") wystapil blad: " << b.what() << endl;
        }
        try{
            auto& DoubleObjectTwo = best_cast<DoubleObject&>(*l[i]);
            cout << __LINE__ << ")--->>" << DoubleObjectTwo.getDoubleContent() << endl;
        }
        catch(const std::bad_cast& b){
            cerr << __LINE__ << ") wystapil blad: " << b.what() << endl;
        }
    }
}
