//
// Created by Егор Назаров on 29.02.2020.
//

#include <iostream>
#include "Menu.h"

Menu::Menu() {}

void Menu::Run() {
    while (true) {
        std::cout << "Commands:" << std::endl;
        std::cout << "'assign <file_name>' - assign file name" << std::endl;
        std::cout << "'open' - open file stream" << std::endl;
        std::cout << "'close' - close file stream" << std::endl;
        std::cout << "'getname' - get assigned file name" << std::endl;
        std::cout << "'open?' - check if stream is open" << std::endl;
        std::cout << "'end?' - check if reached end of file" << std::endl;
        std::cout << "'getstring' - get one line from file" << std::endl;
        std::cout << "'getword' - get one word from file" << std::endl;
        std::cout << "'exit' - exit" << std::endl;

        std::string s;
        std::cout << "> ";
        std::cin >> s;
        Execute(s);
    }
}

void Menu::Execute(const std::string& s) {
    if (s == "assign") {
        std::string name;
        std::cin >> name;
        instance = TextIn(name);
        std::cout << "Name successfully assigned!" << std::endl;
        return;
    }

    if (s == "open") {
        if (instance.openFile())
            std::cout << "File opened successfully!" << std::endl;
        else
            std::cout << "Error opening file!" << std::endl;
        return;
    }

    if (s == "close") {
        instance.closeFile();
        std::cout << "File closed successfully!" << std::endl;
        return;
    }
    if (s == "getname") {
        std::cout << "File name: '" << instance.getFileName() << '\'' << std::endl;
        return;
    }
    if (s == "open?") {
        if (instance.isOpen()) {
            std::cout << "Stream is opened!" << std::endl;
        } else {
            std::cout << "Stream is NOT opened!" << std::endl;
        }
        return;
    }
    if (s == "end?") {
        if (instance.isEnd()) {
            std::cout << "EOF is reached!" << std::endl;
        } else {
            std::cout << "EOF is NOT reached!" << std::endl;
        }
        return;
    }
    if (s == "getstring") {
        std::string output;
        if (instance.getString(output)) {
            std::cout << "String from file: " << output << std::endl;
        } else if (instance.isEnd()) {
            std::cout << "Error reading string! EOF is reached!" << std::endl;
        } else {
            std::cout << "Error reading string!" << std::endl;
        }
        return;
    }
    if (s == "getword") {
        std::string output;
        if (instance.getWord(output)) {
            std::cout << "Word from file: " << output << std::endl;
        } else if (instance.isEnd()) {
            std::cout << "Error reading word! EOF is reached!" << std::endl;
        } else {
            std::cout << "Error reading word!" << std::endl;
        }
        return;
    }
    if (s == "exit") {
        std::cout << "Are you sure you want to exit?\n";
        std::cout << "Y/N?" << std::endl;
        std::cout << "> ";
        while (true)
        {
            char c;
            scanf("%c", &c);
            if (c == 'Y')
            {
                exit(0);
            }
            else if (c == 'N')
            {
                return;
            }
        }
    }
}


