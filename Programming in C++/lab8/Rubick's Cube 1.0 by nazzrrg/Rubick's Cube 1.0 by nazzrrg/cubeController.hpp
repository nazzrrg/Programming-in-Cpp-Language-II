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
#include "cubeView.hpp"
#include <stack>
#include "Shader.hpp"

class cubeController {
private:
public:
    cubeController();
    ~cubeController();
    void shuffle(cubeModel& cube);
    void solve(cubeModel& cube);
    void solverReset();
    void check(cubeModel& cube);
    void reset(cubeModel& cube);
    void rotate(cubeModel& cube, int side, int direction);
    void moveCam(cubeView& cube, float x0, float y0, float x, float y);
    void zoomCam(cubeView& cube, float delta);
    float camX = std::sin(0), camY = std::cos(0), camZ = std::cos(0), dX = 0.0f, dY = 0.0f;
    float cameraRadius = 5.0f;
    std::string moooves;
    bool solveFinishFlag = false;
    int solveRotCnt=0;
    bool solved = false;
};

#endif /* cubeController_hpp */
