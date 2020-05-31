//
//  cubeView.hpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef cubeView_hpp
#define cubeView_hpp

#include <stdio.h>
#include <OpenGL/gl3.h>
#include "Shader.hpp"
#include "cubeModel.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class cubeView {
private:
    bool graphical;
    GLuint texture;
    int screenWidth, screenHeight;
    Shader shader{"/Users/nazzrrg/Git/Programming-in-Cpp-Language-II/Programming in C++/lab8/Test App/Test App/res/shaders/core.vs", "/Users/nazzrrg/Git/Programming-in-Cpp-Language-II/Programming in C++/lab8/Test App/Test App/res/shaders/core.frag"};
    std::vector<GLfloat> vert;
    void setSideData(int sideNum, int color);
public:
    glm::mat4 projection;
    cubeView(bool graphical_, int screenWidth_, int screenHeight_);
    ~cubeView();
    void display(const cubeModel& cube);
    void draw(const cubeModel& cube);
    void print(const cubeModel& cube);
    int getScreenWidth();
    int getScreenHeight();
};

#endif /* cubeView_hpp */
