//
//  fileHandler.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef fileHandler_hpp
#define fileHandler_hpp

#include <stdio.h>
#include <fstream>
#include <sstream>

class fileHandler {
private:
    std::ifstream in;
    std::ofstream out;
public:
    fileHandler();
    ~fileHandler();
    void writeBuffer(std::string filePath, const std::string& buf_str);
    std::string readBuffer(std::string filePath);
};

#endif /* fileHandler_hpp */
