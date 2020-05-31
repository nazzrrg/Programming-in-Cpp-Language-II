//
//  smallCubeModel.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "smallCubeModel.hpp"

smallCubeModel::smallCubeModel() {
    x = y = z = 0;
    sides.resize(6);
}

smallCubeModel::~smallCubeModel() {
}

void smallCubeModel::setCoords(int x_, int y_, int z_) {
    x = x_;
    y = y_;
    z = z_;
}

int smallCubeModel::getX() {
    return x;
}

int smallCubeModel::getY() {
    return y;
}

int smallCubeModel::getZ() {
    return z;
}

void smallCubeModel::setColor() {
    for (int i = 0; i < 6; ++i) {
//        sides[i].setNum(i);
        sides[i] = i;
    }
}

void smallCubeModel::setColor(int side, int color) {
//    sides[side].setNum(color);
    sides[side] = color;
}

int smallCubeModel::getColor(int side) {
//    return sides[side].getNum();
    return sides[side];
}

void smallCubeModel::rotX(int dir) {
    sideType tmp;
    if (dir == 1) {// CW
        tmp = sides[0];
        sides[0] = sides[2];
        sides[2] = sides[5];
        sides[5] = sides[4];
        sides[4] = tmp;
    } else { // CCW
        tmp = sides[0];
        sides[0] = sides[4];
        sides[4] = sides[5];
        sides[5] = sides[2];
        sides[2] = tmp;
    }
}

void smallCubeModel::rotY(int dir) {
    sideType tmp;
    if (dir == 1) {// CW
        tmp = sides[0];
        sides[0] = sides[3];
        sides[3] = sides[5];
        sides[5] = sides[1];
        sides[1] = tmp;
    } else { // CCW
        tmp = sides[0];
        sides[0] = sides[1];
        sides[1] = sides[5];
        sides[5] = sides[3];
        sides[3] = tmp;
    }
}

void smallCubeModel::rotZ(int dir) {
    sideType tmp;
    if (dir == 1) {// CW
        tmp = sides[1];
        sides[1] = sides[2];
        sides[2] = sides[3];
        sides[3] = sides[4];
        sides[4] = tmp;
    } else { // CCW
        tmp = sides[1];
        sides[1] = sides[4];
        sides[4] = sides[3];
        sides[3] = sides[2];
        sides[2] = tmp;
    }
}
