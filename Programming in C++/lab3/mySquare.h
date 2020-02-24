//
// Created by Егор Назаров on 24.02.2020.
//

#ifndef LAB3_MYSQUARE_H
#define LAB3_MYSQUARE_H


#include <utility>
#include <iostream>

class mySquare {
private:
    std::pair<uint64_t, uint64_t> point;
    uint64_t side;
    double angle;

public:
    mySquare();
    mySquare(std::pair<uint64_t, uint64_t>, uint64_t, double);

    int operator==(const mySquare& other);
    int operator!=(const mySquare& other);
    int operator>(const mySquare& other);
    int operator<(const mySquare& other);
    mySquare operator*(const uint64_t& right);
    mySquare operator+(const std::pair<uint64_t, uint64_t>& right);

    friend std::ostream& operator<<(std::ostream&, mySquare&);
};


#endif //LAB3_MYSQUARE_H
