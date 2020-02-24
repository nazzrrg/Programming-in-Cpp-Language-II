#include "mySquare.h"
//
// Created by Егор Назаров on 24.02.2020.
//

#include "mySquare.h"

mySquare::mySquare() {
    point = std::make_pair(0, 0);
    side = 1;
    angle = 0.0;
}

mySquare::mySquare(std::pair<uint64_t, uint64_t> p, uint64_t s, double a) {
    point = p;
    side = s;
    angle = a;
}

int mySquare::operator==(const mySquare &other) {
    return this->side == other.side;
}

int mySquare::operator!=(const mySquare &other) {
    return this->side != other.side;
}

int mySquare::operator>(const mySquare &other) {
    return this->side > other.side;
}

int mySquare::operator<(const mySquare &other) {
    return this->side < other.side;
}

mySquare mySquare::operator*(const uint64_t& right) {
//    this->side*=right;
//    return *this;
    return mySquare(this->point, this->side*right, this->angle);
}

mySquare mySquare::operator+(const std::pair<uint64_t, uint64_t>& right) {
    return mySquare(std::make_pair(point.first + right.first, point.second + right.second), this->side, this->angle);
}

std::ostream &operator<<(std::ostream& out, mySquare& s) {
    out << "Square:" << std::endl << "Point: (" << s.point.first << ", " << s.point.second << ")" << std::endl
        << "Side Length: " << s.side << std::endl << "Angle: " << s.angle << std::endl;

    return out;
}


