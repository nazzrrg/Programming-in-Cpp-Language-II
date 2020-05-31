//
//  cubeModel.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "cubeModel.hpp"
#include <algorithm>
#include <iostream>

cubeModel::cubeModel() {
    int count=0;
    for (auto& item : cubes) {
        item.setColor();
        item.setCoords((int)count%3, (int)(count/3)%3, (int)(count/9)%3);
        count++;
    }
}

cubeModel::~cubeModel() {
}

void cubeModel::rotateSide(int sideNumber, int direction) {
    std::cout << "Rotate " << sideNumber <<' ';
    if (direction == 2) {
        std::cout << "Counter-ClockWise" << std::endl;
    } else {
        std::cout << "ClockWise" << std::endl;
    }
    switch (sideNumber) {
        case 1: { // OK CW by Z CCW by side
            for(auto& item : cubes) {
                if (item.getZ() == -1) {
                    if (direction == 2) {
                        item.rotZ(1);
                        item.setCoords( item.getY(),
                                       -item.getX(),
                                        item.getZ());
                    } else {
                        item.setCoords(-item.getY(),
                                        item.getX(),
                                        item.getZ());
                        item.rotZ(2);
                    }
                }
            }
            break;
        }
        case 2: { // OK CCW by X CCW by side
            for (auto& item : cubes) {
                if (item.getX() == 1) {
                    if (direction == 2) {
                        item.setCoords( item.getX(),
                                       -item.getZ(),
                                        item.getY());
                        item.rotX(2);
                    } else {
                        item.setCoords( item.getX(),
                                        item.getZ(),
                                       -item.getY());
                        item.rotX(1);
                    }
                }
            }
            break;
        }
        case 3: { // OK CCW by side CCW by Y
            for (auto& item : cubes) {
                if (item.getY() == 1) {
                    if (direction == 2) {
                        item.setCoords( item.getZ(),
                                        item.getY(),
                                       -item.getX());
                        item.rotY(2);
                    } else {
                        item.setCoords(-item.getZ(),
                                        item.getY(),
                                        item.getX());
                        item.rotY(1);
                    }
                }
            }
            break;
        }
        case 4: { // OK CCW by side CW by X
            for (auto& item : cubes) {
                if (item.getX() == -1) {
                    if (direction == 2) {
                        item.setCoords( item.getX(),
                                        item.getZ(),
                                       -item.getY());
                        item.rotX(1);
                    } else {
                        item.setCoords( item.getX(),
                                       -item.getZ(),
                                        item.getY());
                        item.rotX(2);
                    }
                }
            }
            break;
        }
        case 5: { // OK CCW by side CW by Y
            for (auto& item : cubes) {
                if (item.getY() == -1) {
                    if (direction == 2) {
                        item.setCoords(-item.getZ(),
                                        item.getY(),
                                        item.getX());
                        item.rotY(1);
                    } else {
                        item.setCoords( item.getZ(),
                                        item.getY(),
                                       -item.getX());
                        item.rotY(2);
                    }
                }
            }
            break;
        }
        case 6: { // OK
            for (auto& item : cubes) {
                if (item.getZ() == 1) {
                    if (direction == 2) {
                        item.setCoords(-item.getY(),
                                        item.getX(),
                                        item.getZ());
                        item.rotY(2);
                    } else {
                        item.setCoords( item.getY(),
                                       -item.getX(),
                                        item.getZ());
                        item.rotZ(1);
                    }
                }
            }
            break;
        }
        default:
            throw std::runtime_error("Error, unsupported rotation");
            break;
    }
}
