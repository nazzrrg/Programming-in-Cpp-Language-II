//
//  CubeAPI.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "CubeAPI.hpp"
#include <sstream>
#include "fileHandler.hpp"

cubeAPI::cubeAPI() {
}
cubeAPI::~cubeAPI() {
}
void cubeAPI::update() {
    viewInstance.display(modelInstance);
}

void cubeAPI::saveFile(std::string filePath) {
    std::stringstream buffer;
    for (auto item : modelInstance.cubes) {
        buffer << std::to_string(item.getX()) << ' ' << std::to_string(item.getY()) << ' ' << std::to_string(item.getZ()) << '\t';
        for (int i = 0; i < 6; ++i) {
            buffer << std::to_string(item.getColor(i)) << ' ';
        }
        buffer << '\n';
    }
    buffer << '\0';
    
    fileHandler file{};
    file.writeBuffer(filePath, buffer.str());
}

void cubeAPI::loadFile(std::string filePath) {
    fileHandler file{};
    std::stringstream buffer(file.readBuffer(filePath));
    for (int i = 0; i < 27; ++i) {
        std::string stringX, stringY, stringZ;
        buffer >> stringX >> stringY >> stringZ;
        int x = std::stoi(stringX), y = std::stoi(stringY), z = std::stoi(stringZ);
        modelInstance.cubes[i].setCoords(x, y, z);
        std::string part;
        for (int j = 0; j < 6; ++j) {
            buffer >> part;
            int color = std::stoi(part);
            modelInstance.cubes[i].setColor(j, color);
        }
    }
}
