//
//  cubeController.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef cubeController_hpp
#define cubeController_hpp

#include <stdio.h>
#include "cubeModel.hpp"

class cubeController {
private:
public:
    cubeController();
    ~cubeController();
    void shuffle(cubeModel& cube);
    void rotate(cubeModel& cube, int side, int direction);
};

#endif /* cubeController_hpp */
