#include <iostream>
#include "MyCircularBuffer.h"

int main() {
    MyCircularBuffer<int> buf(5);
    buf.push_back(1);
    buf.push_back(2);
    buf.push_back(3);
    buf.push_back(4);
    buf.push_back(5);
    buf.push_back(6);
    buf.push_back(7);
    for (int i =0; i < buf.size(); i++) {
        std::cout << buf[i] << ' ';
    }

    std::cout << std::endl;
    buf.pop_front();
    buf.pop_back();
    for (auto item : buf) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    buf.resize(20);
    buf.push_back(8);
    buf.push_front(-2);
    buf.push_front(-3);
    buf.push_front(-2);
    buf.push_front(-3);
    buf.push_front(-2);
    buf.push_front(-3);
    buf.push_back(8);
    buf.push_back(8);
    buf.push_back(8);
    buf.push_back(8);
    for (auto item : buf) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    buf[6] = 2;
    buf[7] = 3;

    for (auto item : buf) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    buf.remove(std::find(buf.begin(), buf.end(), 2));
    for (auto item : buf) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    buf.insert(std::find(buf.begin(), buf.end(), 3), 17);
    for (auto item : buf) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;
    return 0;
}
