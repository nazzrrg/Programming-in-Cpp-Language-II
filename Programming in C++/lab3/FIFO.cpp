//
// Created by Егор Назаров on 24.02.2020.
//

#include <cstdlib>
#include <iostream>
#include "FIFO.h"

FIFO::FIFO() {
    size = 0;
    f = nullptr;
    e = nullptr;
}

std::ostream &operator<<(std::ostream & out, FIFO &f) {
    if (f.size == 0) {
        std::cout << "Error FIFO too small!" << std::endl;
        exit(1);
    }
    out << f.f->val;
    FIFO::node* item = f.f;
    f.f = f.f->next;
    delete item;
    f.size--;
    return out;
}

std::istream &operator>>(std::istream &in, FIFO &f) {
    if (f.size >= f.max_size) {
        std::cout << "Error FIFO too big!" << std::endl;
        exit(1);
    }

    auto *item = new FIFO::node;
    in >> item->val;

    if (f.f == nullptr) {
        f.f = item;
    }
    if (f.e != nullptr) {
        f.e->next = item;
    }
    f.e = item;
    f.size++;
    return in;
}

int32_t FIFO::front() {
    return f->val;
}

bool FIFO::push(int32_t i) {
    if (size == max_size)
        return false;

    auto *item = new FIFO::node;
    item->val = i;

    if (f == nullptr) {
        f = item;
    }
    if (e != nullptr) {
        e->next = item;
    }
    e = item;
    size++;
    return true;
}

bool FIFO::pop() {
    if (size == 0)
        return false;
    FIFO::node* item = f;
    f = f->next;
    size--;
    delete item;
    return true;
}

FIFO::FIFO(const FIFO &f) {
    this->f = nullptr;
    this->e = nullptr;
    this->size = 0;
    node* i = f.f;
    while (i != nullptr) {
        this->push(i->val);
        i = i->next;
    }
}


