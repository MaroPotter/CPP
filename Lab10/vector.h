#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // size_t
#include <exception>
#include <stdexcept>
#include <memory>

/**
 * 1. konstruktory – domyślny (nic nie robiący),
 *    kopiujący, przenoszący, destruktor
 * 2. konstruktory – kopiujący z innego kontenera
 *    i kolejny konstruktor z tablicy statycznej.
 * 3. a) metoda push_back(T t) – dodaje element na koniec,
 *       w razie braku miejsca dokonuje reallokacji
 *    b) metoda pop_back(), która usuwa element z końca
 * 4. a) metoda at(size_t index), która w razie wyjścia poza zakres wyrzuci wyjątek
 *    b) metoda size() zwracająca rozmiar
 * 5. a) proszę zamiast ręcznego zarządzania pamięcią zamienić to co w środku
 *       na unique_ptr<T[]> data;
 *    b) proszę o zamianę aby jako parametr szablonu naszego Vectora podawać
 *       również ilość elementów do dodawania przy realokacji:
 * 6. Prosze o zaimplementowanie mechanizmu do iteracji, aby działało for-each
 * 7. Proszę o zaimplementowanie metody count if wraz z przykładowym
 *    predykatem (własnym, lub standardowym, bez lambd)
 */
template<typename T, size_t resize_step = 5>
class Vector
{
    std::unique_ptr<T[]> _data = nullptr;
    size_t _size = 0;
    size_t _capacity = 0;
public:
    /// 1:
    Vector() = default;

    ~Vector()
    {
        _data.reset();
        _size = 0;
        _capacity = 0;
    }
    Vector(const Vector &v);

    Vector(Vector&& v)
            : _size(v._size), _capacity(v._capacity), _data(move(v._data)){
        v._size = v._capacity = 0;
    }
    /// 2:
    template<typename Container>
    Vector(const Container& container) : _size(container.size()),
                                         _capacity(_size), _data(new T [_size])
    {
        copy(begin(container), end(container), _data.get());
    }

    template<size_t N>
    Vector(const T(&staticArray)[N]);
    /// 3: niezrobione
//    void push_back(T t);
//    void pop_back();
    /// 4:
    T& at(size_t index) const;

    size_t size() const;
    /// 5:

    /// 6:

    /// 7: (predykat w testach)
    template<typename Predicate>
    size_t count_if(Predicate predicate)
    {
        size_t counter = {};
        for (size_t i=0; i<_size; ++i)
            if (predicate(_data[i]))
            {
                counter++;
            }
        return counter;
//        alternatywnie
//        return count_if(_data.get(), _data.get()+_size, predicate);
    }
};

template<typename T, size_t resize_step>
Vector<T, resize_step>::Vector(const Vector &v)
        : _capacity(v._capacity), _size(v._size)
{
    _data.reset(new T[_size]);
    for (auto i = 0; i < _size; ++i) {
        _data[i] = v._data[i];
    }
}

template<typename T, size_t resize_step>
T &Vector<T, resize_step>::at(size_t index) const {
    if(index>=_size)
    {
        throw std::out_of_range("...");
    }
    return _data[index];
}

template<typename T, size_t resize_step>
size_t Vector<T, resize_step>::size() const
{
    return _size;
}

template<typename T, size_t resize_step>
template<size_t N>
Vector<T, resize_step>::Vector(const T(&staticArray)[N]): _data(new T[N]), _capacity(N), _size(N){
    for(unsigned i = 0; i < N; i++){
        _data[i] = staticArray[i];
    }
    // alternatywnie:
    // copy(staticArray, staticArray + N, data);
}

#endif // VECTOR_H
