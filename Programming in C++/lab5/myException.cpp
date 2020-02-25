//
// Created by Егор Назаров on 25.02.2020.
//

#include "myException.h"
#include <exception>
#include <utility>

myException::myException(std::string msg_) {
    msg = std::move(msg_);
}

myException::myException(std::string msg_, int c_) {
    msg = std::move(msg_);
    c = c_;
}

int myException::code() {
    return c;
}

std::string myException::what() {
    return msg;
}
