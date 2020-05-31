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
    cubeModel modelInstance;
    cubeView  viewInstance{true, 800, 600};
public:
    cubeAPI();
    void update();
    ~cubeAPI();
    void saveFile(std::string filePath);
    void loadFile(std::string filePath);
    void newFile();
};

#endif /* CubeAPI_hpp */
