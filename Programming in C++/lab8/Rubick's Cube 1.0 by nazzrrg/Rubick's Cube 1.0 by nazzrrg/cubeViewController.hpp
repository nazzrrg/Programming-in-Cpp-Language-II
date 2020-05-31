//
//  viewController.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef viewController_hpp
#define viewController_hpp

#include <stdio.h>
#include "cubeView.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class cubeViewController {
public:
    cubeViewController();
    ~cubeViewController();
    void moveCamera (cubeView& view);
};

#endif /* viewController_hpp */
