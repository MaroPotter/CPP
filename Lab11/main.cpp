#include <iostream>
#include <typeinfo>
#include "../Lab5/list.h"
using namespace std;
template <typename T>
void PrintType(const T& t)
{

}
int main() {
    List l;
    l.push_back(new DoubleObject(4));
    l.push_back(new StringObject("Crazy text"));
    for(decltype(l.size()) i = 0; i<l.size() ; ++i)
    {

        if(typeid(*l[i])== typeid(DoubleObject))
        {
                DoubleObject ddd = dynamic_cast<DoubleObject&>(*l[i]);
                cout<<ddd.whatAmI()<<" "<<typeid(l[i]).name()<<'\n';
        }
         try {
            DoubleObject &d = dynamic_cast<DoubleObject&>(*l[i]);
            cout<<"->>>>>>" << d%2 << endl;
        }
        catch(const bad_cast& e) {
            cerr<<"wyjatek"<<e.what() << endl;
            throw; //ponownie rzucamy wyjątek, alternatywnie: throw e;
        }



    }
     /*
        if(DoubleObject *dd = dynamic_cast<DoubleObject*>(l[i]))
            cout<< "----->" << (*dd)%2 << endl;
            */
    return 0;
}