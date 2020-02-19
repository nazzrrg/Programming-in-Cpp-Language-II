#ifndef LAB2_TEXTIN_H
#define LAB2_TEXTIN_H


#include <cstdio>
#include <string>

class TextIn {
private:
    char* path;
    FILE * f;

public:
    TextIn();
    explicit TextIn(const std::string&);
    explicit TextIn(char*);
    bool openFile();
    bool closeFile();
    std::string getFileName();
    bool isOpen();
    bool isEnd();
    bool getString(std::string&);
    bool getWord(std::string&);
};


#endif //LAB2_TEXTIN_H
