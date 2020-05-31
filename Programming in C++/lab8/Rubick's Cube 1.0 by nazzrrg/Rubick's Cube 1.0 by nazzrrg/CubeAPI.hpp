//
//  CubeAPI.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef CubeAPI_hpp
#define CubeAPI_hpp

#include <stdio.h>
#include "cubeModel.hpp"
#include "cubeView.hpp"
#include "cubeController.hpp"
#include <string>


class cubeAPI {
private:
public:
    cubeModel modelInstance;
    cubeView* viewInstance;
    cubeController controllerInstance;
    cubeAPI(float width, float height);
    void update();
    ~cubeAPI();
    void resizeViewWindow(float width, float height);
    void saveFile(std::string filePath);
    void loadFile(std::string filePath);
    void newFile();
    void rotateSide(int side, int direction);
    void moveCamera(float x0, float y0, float x, float y);
    void zoomCamera(float deltaY);
    void solve();
    void shuffle();
    void check();
    void reset();
};

#endif /* CubeAPI_hpp */
