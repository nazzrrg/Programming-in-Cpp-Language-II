//
//  smallCube.cpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "smallCube.h"
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <vector>

smallCube::smallCube(int cubeIndex_, int sw_, int sh_) {
    x = y = z = 0;
    screenHeight = sh_;
    screenWidth = sw_;
    sides.resize(6);
}

void smallCube::rotX(int dir) {
    smallCubeSide tmp;
    if (dir == 1) {// CW
        tmp = sides[0];
        sides[0] = sides[2];
        sides[2] = sides[5];
        sides[5] = sides[4];
        sides[4] = tmp;
    } else { // CCW
        tmp = sides[0];
        sides[0] = sides[4];
        sides[4] = sides[5];
        sides[5] = sides[2];
        sides[2] = tmp;
    }
}

void smallCube::rotY(int dir) {
    smallCubeSide tmp;
    if (dir == 1) {// CW
        tmp = sides[0];
        sides[0] = sides[3];
        sides[3] = sides[5];
        sides[5] = sides[1];
        sides[1] = tmp;
    } else { // CCW
        tmp = sides[0];
        sides[0] = sides[1];
        sides[1] = sides[5];
        sides[5] = sides[3];
        sides[3] = tmp;
    }
}

void smallCube::rotZ(int dir) {
    smallCubeSide tmp;
    if (dir == 1) {// CW
        tmp = sides[1];
        sides[1] = sides[2];
        sides[2] = sides[3];
        sides[3] = sides[4];
        sides[4] = tmp;
    } else { // CCW
        tmp = sides[1];
        sides[1] = sides[4];
        sides[4] = sides[3];
        sides[3] = sides[2];
        sides[2] = tmp;
    }
}

smallCube::smallCube(const smallCube& other) {
    x = other.x;        y = other.y;    z = other.z;
    vertices.reserve(sizeof(GLfloat)*180);
    vertices = other.vertices;
    sides.reserve(sizeof(smallCubeSide)*6);
    sides = other.sides;
    screenWidth = other.screenWidth;    screenHeight = other.screenHeight;
//    view = other.view;              model = other.model;
}

smallCube::~smallCube() {
//    std::cout << "smallCube destruc" << std::endl;
    
}

void smallCube::setCoords(int x_, int y_, int z_) {
    x = x_;
    y = y_;
    z = z_;
}

int smallCube::getX() {
    return x;
}

int smallCube::getY() {
    return y;
}

int smallCube::getZ() {
    return z;
}

void smallCube::setColor() {
    for (int i = 0; i < 6; ++i) {
        sides[i].setNum(i);
    }
}

void smallCube::setColor(int side, int color) {
    sides[side].setNum(color);
}

int smallCube::getColor(int side) {
    return sides[side].getNum();
}

void smallCube::draw(const unsigned int& texture, GLfloat timeStamp, const Shader& ourShader, const glm::mat4& projection) {
    
    std::vector<GLfloat> vert = {
        -0.5f, -0.5f, -0.5f,    sides[0].bottomLeft.x,  sides[0].bottomLeft.y,
        0.5f, -0.5f, -0.5f,     sides[0].topLeft.x,     sides[0].topLeft.y,
        0.5f,  0.5f, -0.5f,     sides[0].topRight.x,    sides[0].topRight.y,
        0.5f,  0.5f, -0.5f,     sides[0].topRight.x,    sides[0].topRight.y,
        -0.5f,  0.5f, -0.5f,    sides[0].bottomRight.x, sides[0].bottomRight.y,
        -0.5f, -0.5f, -0.5f,    sides[0].bottomLeft.x,  sides[0].bottomLeft.y,
        
        0.5, -0.5, -0.5,        sides[1].bottomLeft.x,  sides[1].bottomLeft.y,
        0.5, 0.5, -0.5,         sides[1].bottomRight.x, sides[1].bottomRight.y,
        0.5, -0.5, 0.5,         sides[1].topLeft.x,     sides[1].topLeft.y,
        0.5, -0.5, 0.5,         sides[1].topLeft.x,     sides[1].topLeft.y,
        0.5 ,0.5, 0.5,          sides[1].topRight.x,    sides[1].topRight.y,
        0.5, 0.5, -0.5,         sides[1].bottomRight.x, sides[1].bottomRight.y,
        
        0.5, 0.5, -0.5,         sides[2].bottomLeft.x,  sides[2].bottomLeft.y,
        -0.5, +0.5, -0.5,       sides[2].bottomRight.x, sides[2].bottomRight.y,
        0.5, 0.5, 0.5,          sides[2].topLeft.x,     sides[2].topLeft.y,
        0.5, 0.5, 0.5,          sides[2].topLeft.x,     sides[2].topLeft.y,
        -0.5, 0.5, 0.5,         sides[2].topRight.x,    sides[2].topRight.y,
        -0.5, 0.5, -0.5,        sides[2].bottomRight.x, sides[2].bottomRight.y,
        
        -0.5, 0.5, -0.5,        sides[3].bottomLeft.x,  sides[3].bottomLeft.y,
        -0.5, -0.5, -0.5,       sides[3].bottomRight.x, sides[3].bottomRight.y,
        -0.5, 0.5, 0.5,         sides[3].topLeft.x,     sides[3].topLeft.y,
        -0.5, 0.5, 0.5,         sides[3].topLeft.x,     sides[3].topLeft.y,
        -0.5, -0.5, 0.5,        sides[3].topRight.x,    sides[3].topRight.y,
        -0.5, -0.5, -0.5,       sides[3].bottomRight.x, sides[3].bottomRight.y,
        
        -0.5, -0.5, -0.5,       sides[4].bottomLeft.x,  sides[4].bottomLeft.y,
        0.5, -0.5, -0.5,        sides[4].bottomRight.x, sides[4].bottomRight.y,
        -0.5, -0.5, 0.5,        sides[4].topLeft.x,     sides[4].topLeft.y,
        -0.5, -0.5, 0.5,        sides[4].topLeft.x,     sides[4].topLeft.y,
        0.5, -0.5, 0.5,         sides[4].topRight.x,    sides[4].topRight.y,
        0.5, -0.5, -0.5,        sides[4].bottomRight.x, sides[4].bottomRight.y,
        
        0.5, -0.5, 0.5,         sides[5].bottomLeft.x,  sides[5].bottomLeft.y,
        0.5, 0.5, 0.5,          sides[5].bottomRight.x, sides[5].bottomRight.y,
        -0.5, -0.5, 0.5,        sides[5].topLeft.x,     sides[5].topLeft.y,
        -0.5, -0.5, 0.5,        sides[5].topLeft.x,     sides[5].topLeft.y,
        -0.5, 0.5, 0.5,         sides[5].topRight.x,    sides[5].topRight.y,
        0.5, 0.5, 0.5,          sides[5].bottomRight.x, sides[5].bottomRight.y
    };
    
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert)*vert.size(), &vert[0], GL_DYNAMIC_DRAW);
    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *) 0);
    glEnableVertexAttribArray(0);
    // Texture Coordinate attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid *)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    
//    glBindVertexArray(0); // Unbind VAO
//
//    glBindVertexArray(VAO);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture"), 0);
        
    ourShader.Use();
    
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(x, y, z));
    
//    GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
    GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
    GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
            
//    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            
    // Draw container
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}
