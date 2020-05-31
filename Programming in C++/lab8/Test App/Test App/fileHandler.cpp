//
//  fileHandler.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "fileHandler.hpp"

fileHandler::fileHandler() {
    
}
fileHandler::~fileHandler() {
    
}

void fileHandler::writeBuffer(std::string filePath, const std::string &buf_str) {
    out.open(filePath.c_str());
    if (out.is_open()) {
        out << buf_str;
        out.flush();
        out.close();
    } else {
        throw std::runtime_error("Error opening output file");
    }
}

std::string fileHandler::readBuffer(std::string filePath) {
    in.open(filePath.c_str());
    if (in.is_open()) {
        std::stringstream buffer;
        buffer << in.rdbuf();
        buffer << '\0';
        std::string output = buffer.str();
        in.close();
        return output;
    } else {
        throw std::runtime_error("Error opening input file");
    }
    return NULL;
}
