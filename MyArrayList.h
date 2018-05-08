#include <stdlib.h>
#include <stdexcept>

using namespace std;

template <typename T> class MyArrayList
{
    public:
        MyArrayList();
        MyArrayList(int cap);
        MyArrayList(int cap, int scale);
        void append(T value);
        T get(int index);
        int size();
    private:
        T* values;
        int capacity;
        int pointer;
        int scale_factor;
        void copyOverValues(T* new_array);
};


template <typename T>
MyArrayList<T>::MyArrayList() {
    capacity = 10;
    pointer = 0;
    scale_factor = 2;
    values = (T*) malloc(capacity*sizeof(T));
}

template <typename T>
MyArrayList<T>::MyArrayList(int cap) {
    capacity = cap;
    pointer = 0;
    scale_factor = 2;
    values = (T*) malloc(capacity*sizeof(T));
}

template <typename T>
MyArrayList<T>::MyArrayList(int cap, int scale_factor) {
    capacity = cap;
    pointer = 0;
    scale_factor = scale_factor;
    values = (T*) malloc(capacity*sizeof(T));
}

template <typename T>
void MyArrayList<T>::append(T value) {
    if (pointer < capacity) {
        values[pointer] = value;
        pointer++;
    } else {
        // Expand the array list
        capacity = capacity*scale_factor;
        T* new_array = (T*) malloc(capacity*sizeof(T));
        this->copyOverValues(new_array); // At this point values should be copied across
        free(values);
        values = new_array;
    }
}

template <typename T>
int MyArrayList<T>::size() {
    return pointer;
}

template <typename T>
void MyArrayList<T>::copyOverValues(T* new_array) {
    for (int i = 0; i < pointer; i++) {
        new_array[i] = values[i];
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