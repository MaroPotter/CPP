#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> getKeysFromMap(const map<int,string>& m)
{
    vector<int> v;
    for (const auto& item : m)
    {
        v.push_back(item.first);
    }
// alternatywnie:
//    for (map<int,string>::const_iterator it=m.begin(); it!=m.end(); ++it)
//    {
//        v.push_back(it->first);
//    }
    return v;
}

map<string,int> getMapValue2Key(const map<int,string>& m)
{
    map<string,int> m2;
    for (const auto& item : m)
    {
        m2.insert(pair<string,int>(item.second, item.first));
        // alternatywnie dowolne z ponizszych:
//        m2.insert(pair(item.second, item.first));
//        m2.insert(make_pair(item.second, item.first));
//        m2[item.second] = item.first;
    }
    // alternatywna petla jw.
    return m2;
}

