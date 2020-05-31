//
//  smallCube.h
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef smallCube_h
#define smallCube_h

#include <stdio.h>
#include <vector>
#include "smallCubeSide.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"

class smallCube {
private:
    int screenWidth, screenHeight; // 
    std::vector<smallCubeSide> sides; // надо хранить
    int x, y, z; // надо хранить
    std::vector<GLfloat> vertices; // после init
public:
    smallCube(int cubeIndex = 0, int sw_ = 800, int sh_=600);
    smallCube(const smallCube& other);
    ~smallCube();
    void setCoords(int x_, int y_, int z_);
    void setColor();
    void setColor(int side, int color);
    int getColor(int side);
    void draw(const GLuint& texture, GLfloat timeStamp, const Shader& ourShader, const glm::mat4& projection);
    void init();
    int getZ();
    int getY();
    int getX();
    void rotX(int dir);
    void rotY(int dir);
    void rotZ(int dir);
};

#endif /* smallCube_h */
