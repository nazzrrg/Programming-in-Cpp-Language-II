//
// Created by Егор Назаров on 25.02.2020.
//

#ifndef LAB5_MYEXCEPTION_H
#define LAB5_MYEXCEPTION_H


#include <exception>
#include <string>

class myException {
public:
    myException(std::string);
    myException(std::string, int);
    int code();
    std::string what();

private:
    std::string msg;
    int c;
};


#endif //LAB5_MYEXCEPTION_H
