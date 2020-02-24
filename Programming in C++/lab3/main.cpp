#include <iostream>
#include "mySquare.h"
#include "FIFO.h"
int main() {

    mySquare s;
    std::cout << std::endl << "s: " << std::endl << s;
    s = s + std::make_pair(1, 2);
    mySquare s1 = s * 2;
    std::cout << std::endl << "s1: " << std::endl << s1 << std::endl;
    if (s1 == s) {
        std::cout << "s1 == s: YES" <<std::endl;
    } else {
        std::cout << "s1 == s: NO" <<std::endl;
    }
    if (s1 != s) {
        std::cout << "s1 != s: YES" <<std::endl;
    } else {
        std::cout << "s1 != s: NO" <<std::endl;
    }
    if (s1 < s) {
        std::cout << "s1 < s: YES" <<std::endl;
    } else {
        std::cout << "s1 < s: NO" <<std::endl;
    }
    if (s1 > s) {
        std::cout << "s1 > s: YES" <<std::endl;
    } else {
        std::cout << "s1 > s: NO" <<std::endl;
    }

    FIFO fifa;

    int32_t a;
    fifa.push(12);
    std::cin >> fifa >> fifa;
    std::cout << fifa << std::endl;
    std::cout << fifa << std::endl;
    fifa.pop();
    std::cout << fifa << std::endl;
    return 0;
}
