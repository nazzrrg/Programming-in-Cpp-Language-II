//
// Created by Егор Назаров on 29.02.2020.
//

#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include "TextIn.h"


class Menu {
public:
    Menu();
    void Run();

private:
    TextIn instance;

    void Execute(const std::string& s);
};


#endif //LAB2_MENU_H
