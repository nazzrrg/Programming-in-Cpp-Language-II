#include <iostream>
#include "TextIn.h"

int main() {
    TextIn file1("input.txt");
    TextIn file2("input2.txt");
    file1.openFile();
    file2.openFile();
    std::cout << "File 1 is open: " << file1.isOpen() << std::endl;
    std::cout << "File 2 is NOT open: " << file2.isOpen() << std::endl;
    std::cout << "File 1 name: " << file1.getFileName() << std::endl;
    std::cout << "File 2 name: " << file2.getFileName() << std::endl;

    std::string s;
    if (file1.getString(s))
        std::cout << "File 1 read string: " << s << std::endl;
    else
        std::cout << "File 1 error reading string" << std::endl;
    if (file2.getString(s))
        std::cout << "File 2 read string: " << s << std::endl;
    else
        std::cout << "File 2 error reading string" << std::endl;

    if (file1.getWord(s))
        std::cout << "File 1 read word: " << s << std::endl;
    else
        std::cout << "File 1 error reading word" << std::endl;
    if (file2.getWord(s))
        std::cout << "File 2 read word: " << s << std::endl;
    else
        std::cout << "File 2 error reading word" << std::endl;

    if (file1.getWord(s))
        std::cout << "File 1 read word: " << s << std::endl;
    else
        std::cout << "File 1 error reading word" << std::endl;
    if (file2.getWord(s))
        std::cout << "File 2 read word: " << s << std::endl;
    else
        std::cout << "File 2 error reading word" << std::endl;

    if (file1.getString(s))
        std::cout << "File 1 read string: " << s << std::endl;
    else
        std::cout << "File 1 error reading string" << std::endl;
    if (file2.getString(s))
        std::cout << "File 2 read string: " << s << std::endl;
    else
        std::cout << "File 2 error reading string" << std::endl;

    std::cout << "File 1 is at end: " << file1.isEnd() << std::endl;
    std::cout << "File 2 is at end or not opened: " << file2.isEnd() << std::endl;

    return 0;
}
