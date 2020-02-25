//
// Created by Егор Назаров on 25.02.2020.
//

#include "myArray.h"
#include "myException.h"

template<class T>
myArray<T>::myArray() {
    size = 100;
    arr = new T[size];
}

template<class T>
myArray<T>::myArray(int size_) {
    size = size_;
    arr = new T[size];
}

template<class T>
T &myArray<T>::operator[](int i) {
    if (i > 0 && i < size)
        return arr[i];
    else
        throw myException("Index subscript out of range", 1);
}
