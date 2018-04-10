#include <stdlib.h>
#include <stdexcept>

using namespace std;

template <typename T> class MyArrayList
{
    public:
        MyArrayList();
        MyArrayList(int cap);
        void append(T value);
        T get(int index);
    private:
        T* values;
        int capacity;
        int pointer;
};


template <typename T>
MyArrayList<T>::MyArrayList() {
    capacity = 10;
    pointer = 0;
    values = (T*) malloc(capacity*sizeof(T));
}

template <typename T>
MyArrayList<T>::MyArrayList(int cap) {
    capacity = cap;
    pointer = 0;
    values = (T*) malloc(capacity*sizeof(T));
}

template <typename T>
void MyArrayList<T>::append(T value) {
    if (pointer < capacity) {
        values[pointer] = value;
        pointer++;
    }
}

template <typename T>
T MyArrayList<T>::get(int index) {
    if (index >= capacity || index < 0) {
        // Throw an exception
        throw out_of_range("MyArrayList: trying to access undefined value");
    }
    return values[index];
}