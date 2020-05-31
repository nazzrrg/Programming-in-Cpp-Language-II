//
//  cubeViewController.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include <cubeViewController.hpp>


cubeViewController::cubeViewController(){}
cubeViewController::~cubeViewController(){}

void cubeViewController::moveCamera(cubeView& view) {
    view.projection = glm::perspective(45.0f, (GLfloat)view.getScreenWidth()/view.getScreenHeight(), 0.1f, 2000.0f) * glm::lookAt(glm::vec3(6.0, 6.0, 6.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
}
