//
//  cubeController.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "cubeController.hpp"
#include <random>
#include <iostream>

cubeController::cubeController() {}
cubeController::~cubeController() {}

void cubeController::shuffle(cubeModel& cube) {
    std::random_device rd;
    std::mt19937 mt(rd());
    int count = mt()% 500;
    for (int i = 0; i < count; ++i) {
        std::mt19937 mt1(rd());
        int number = mt1();
        cube.rotateSide(i%6+1, number%2+1);
        std::cout << number << std::endl;
    }
    std::cout << "Total operations: " << count << std::endl;
}

void cubeController::rotate(cubeModel& cube, int side, int direction) {
    cube.rotateSide(side, direction);
}
