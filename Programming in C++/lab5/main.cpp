#include <iostream>
#include "myException.h"
#include "myArray.h"
#include "myArray.cpp"

template <typename T>
double myPow(const T& n, const int p) {
    if (p == 0) {
        return 1;
    }
    if (p > 0) {
        double res = n;
        for (int i = 1; i < p; i++) {
            res *= n;
        }
        return res;
    }
    if (p < 0) {
        double res = 1;
        for (int i = p; i < 0; i++) {
            res /= n;
        }
        return res;
    }
    return 0;
}

int main() {

    int b = 5;
    std::cout << myPow(b, -1) << std::endl;

    myArray<int> a(10);
    a[1] = 10;
    try {
        std::cout << a[1] << std::endl;
    } catch (myException &ex) {
        std::cout << "Message: " << ex.what() << std::endl;
        std::cout << "Code: " << ex.code() << std::endl;
    }
    try {
        std::cout << a[10] << std::endl;
    } catch (myException &ex) {
        std::cout << "Message: " << ex.what() << std::endl;
        std::cout << "Code: " << ex.code() << std::endl;
    }


    return 0;
}
