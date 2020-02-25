#include <iostream>
#include <vector>
#include <set>
#include "common.h"
//#include "common.tpp"

bool f(int x) {
    return x > 0;
}

int main() {
    std::vector<int> A = {1, 5, 3};
    std::set<double> B = {-1, 2, 3.};
    std::cout << noneOf(A, &f) << " : " << noneOf(B, &f) << std::endl;
    std::cout << isSorted(A, &f) << " : " << isSorted(B, &f) << std::endl;

    std::cout << findNot(A.begin(), A.end(), 1) << " : " << findNot(B.begin(), B.end(), 1) << std::endl;
}