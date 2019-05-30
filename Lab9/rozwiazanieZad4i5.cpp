#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

class Vector {
    unsigned size;
    double *data;
public:
    Vector(unsigned size): size(size), data(new double[size]{})
    {}
    Vector(const Vector& v) : size(v.size)
    {
        if (v.data)
        {
            data = new double[size];
            copy(v.data, v.data+v.size, data);
        }
        else {
            data = nullptr;
        }
    }
    ~Vector()
    {
        delete [] data;
        data = nullptr;
        size = 0;
    }
    Vector& operator=(const Vector& v)
    {
        if (this != &v)
        {
            if (v.data)
            {
                auto* newData = new double[v.size];
                copy(v.data, v.data+v.size, data);
                size = v.size;

                delete [] data;
                data = newData;
            }
            else {
                delete [] data;
                data = nullptr;
            }
        }
        return *this;
    }
    double get(unsigned index) const
    {
        return data[index];
    }
    void set(unsigned index, double value)
    {
        data[index] = value;
    }
    unsigned getSize() const
    {
        return size;
    }

    double* begin()
    {
        return data;
    }
    double* end()
    {
        return data + size;
    }
};
