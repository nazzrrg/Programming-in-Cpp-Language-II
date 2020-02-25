#include <iostream>
#include <vector>
#include <set>
#include "common.h"

bool foo(int x) {
    return x < 0;
}
bool bar(int x, int y) {
    return x < y;
}
int main() {
    std::vector<int> A = {1, 5, 3};
    std::set<double> B = {-1, 2, 3.};
    std::cout << noneOf(A.begin(), A.end(), foo) << " : " << noneOf(B.begin(), B.end(), foo) << std::endl;
    std::cout << isSorted(A.begin(), A.end(), bar) << " : " << isSorted(B.begin(), B.end(), bar) << std::endl;
    std::cout << findNot(A.begin(), A.end(), 1) << " : " << findNot(B.begin(), B.end(), 1) << std::endl;
}