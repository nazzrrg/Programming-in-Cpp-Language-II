//
// Created by Егор Назаров on 25.02.2020.
//

#ifndef LAB5_MYARRAY_H
#define LAB5_MYARRAY_H

template <class T>
class myArray {
private:
    int size;
    T* arr;
public:
    myArray();
    explicit myArray(int);
    T&operator[] (int);
};



#endif //LAB5_MYARRAY_H
