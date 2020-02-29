#include "TextIn.h"

#include <utility>

TextIn::TextIn() {
    path = strdup("input.txt");
    f = nullptr;
    open = false;
}
TextIn::TextIn(const std::string& p) {
    path = strdup(p.c_str());
    f = nullptr;
    open = false;
}
TextIn::TextIn(char* p) {
    path = strdup(p);
    f = nullptr;
    open = false;
}

bool TextIn::openFile() {
    f = fopen(path, "r");
    open = true;
    return (f != nullptr);
}
void TextIn::closeFile() {
    fclose(f);
    open = false;
    f = nullptr;
}
std::string TextIn::getFileName() {
    return std::string(path);
}
bool TextIn::isOpen() {
    return (open);
}
bool TextIn::isEnd() {
    if (isOpen())
        return feof(f);
    return true;
}
bool TextIn::getString(std::string& s) {
    if (!isOpen()) {
        s.clear();
        return false;
    }
    char* c = new char[2048];
    if(!fgets(c, 2048, f)) {
        s.clear();
        return false;
    }
    s = std::string(c);
    return true;
}
bool TextIn::getWord(std::string& s) {
    if (!isOpen()) {
        s.clear();
        return false;
    }
    char* c = new char[2048];
    if(!fscanf(f, "%2047s", c)) {
        s.clear();
        return false;
    }
    s = std::string(c);
//    s = s.substr(0, s.find(' '));

    return true;
}

TextIn::TextIn(const TextIn& other) {
    this->path = strdup(other.path);
    this->open = other.open;
    if (other.open) {
        this->f = fopen(path, "r");
    } else {
        this->f = nullptr;
    }
}
