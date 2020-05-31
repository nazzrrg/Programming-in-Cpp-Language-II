//
//  CubeAPI.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "CubeAPI.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include "fileHandler.hpp"
#include <exception>
#include <Shader.hpp>

cubeAPI::cubeAPI(float width, float height) {
    viewInstance = new cubeView(true, width, height);
}
cubeAPI::~cubeAPI() {
}
void cubeAPI::update() {
    viewInstance->display(modelInstance);
}

void cubeAPI::resizeViewWindow(float width, float height) {
    viewInstance->setScreenWidth(width);
    viewInstance->setScreenHeight(height);
    viewInstance->updateProjection();
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

void cubeAPI::rotateSide(int side, int direction) {
    controllerInstance.rotate(modelInstance, side, direction);
}

void cubeAPI::moveCamera(float x0, float y0, float x, float y) {
    controllerInstance.moveCam(*viewInstance, x0, y0, x, y);
}

void cubeAPI::zoomCamera(float deltaY) {
    controllerInstance.zoomCam(*viewInstance, deltaY);
}

void cubeAPI::shuffle() {
    controllerInstance.shuffle(modelInstance);
}

void cubeAPI::solve() {
    controllerInstance.solve(modelInstance);
}

void cubeAPI::check(){
    controllerInstance.check(modelInstance);
}

void cubeAPI::reset() {
    controllerInstance.reset(modelInstance);
}
