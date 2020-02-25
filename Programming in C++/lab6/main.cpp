#include <iostream>
#include <vector>
#include <set>
#include "common.h"
//#include "common.tpp"

bool foo(int x) {
    return x > 0;
}

int main() {
    std::vector<int> A = {1, 2, 3};
    std::set<double> B = {1., 2., 3.};
    std::cout << noneOf(A, &foo) << " : " << noneOf(B, &foo) << "\n";
    std::cout << isSorted(A, &foo) << " : " << isSorted(B, &foo) << "\n";

    std::cout << findNot(A.begin(), A.end(), 1) << " : " << findNot(B.begin(), B.end(), 1) << "\n";
}