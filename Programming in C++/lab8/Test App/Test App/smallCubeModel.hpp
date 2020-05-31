//
//  smallCube.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef smallCubeModel_hpp
#define smallCubeModel_hpp

#include <stdio.h>
#include <vector>

using sideType = int;

class smallCubeModel {
public:
    std::vector<sideType> sides;
    int x, y, z;
public:
    smallCubeModel();
    ~smallCubeModel();
    void rotX(int dir);
    void rotY(int dir);
    void rotZ(int dir);
    void setCoords(int x_, int y_, int z_);
    int getX();
    int getY();
    int getZ();
    void setColor();
    void setColor(int side, int color);
    int getColor(int side);
};

#endif /* smallCube_hpp */
