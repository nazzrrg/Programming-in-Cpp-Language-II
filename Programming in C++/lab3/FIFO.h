//
// Created by Егор Назаров on 24.02.2020.
//

#ifndef LAB3_FIFO_H
#define LAB3_FIFO_H


#include <cstdint>

class FIFO {
private:
    const int max_size = 100;
    uint16_t size;
    struct node {
        int32_t val;
//        node* bef;
        node* next;
    };
    node* f;
    node* e;
public:
    FIFO();
    FIFO(const FIFO& f);

    int32_t front();
    bool push(int32_t);
    bool pop();

    friend std::ostream& operator<<(std::ostream&, FIFO&);
    friend std::istream& operator>>(std::istream&, FIFO&);
};


#endif //LAB3_FIFO_H
