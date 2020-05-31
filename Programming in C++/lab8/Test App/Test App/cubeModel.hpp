//
//  cubeModel.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef cubeModel_hpp
#define cubeModel_hpp

#include <stdio.h>
#include "smallCubeModel.hpp"

using smallCubeType = smallCubeModel;

class cubeModel {
private:
public:
    std::vector<smallCubeType> cubes{27};
public:
    cubeModel();
    ~cubeModel();
    void rotateSide(int sideNumber, int direction);
};

#endif /* cubeModel_hpp */
