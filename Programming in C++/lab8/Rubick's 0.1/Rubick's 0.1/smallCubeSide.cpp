//  smallCubeSide.cpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "smallCubeSide.h"

smallCubeSide::smallCubeSide() {
}

smallCubeSide::~smallCubeSide() {
}

smallCubeSide::smallCubeSide(const smallCubeSide& other) {
    nNum = other.nNum;
    topRight = other.topRight;
    topLeft = other.topLeft;
    bottomRight = other.bottomRight;
    bottomLeft = other.bottomLeft;
}
smallCubeSide& smallCubeSide::operator=(const smallCubeSide& other) {
    nNum = other.nNum;
    topRight = other.topRight;
    topLeft = other.topLeft;
    bottomRight = other.bottomRight;
    bottomLeft = other.bottomLeft;
    return *this;
}
int smallCubeSide::getNum() {
    return nNum;
}
void smallCubeSide::setNum(int n) {
    nNum = n;
    topLeft = {n/7.0f, 1.0};
    topRight = {(n+1)/7.0f, 1.0};
    bottomLeft = {n/7.0f, 0.0};
    bottomRight = {(n+1)/7.0f, 0.0};
}
