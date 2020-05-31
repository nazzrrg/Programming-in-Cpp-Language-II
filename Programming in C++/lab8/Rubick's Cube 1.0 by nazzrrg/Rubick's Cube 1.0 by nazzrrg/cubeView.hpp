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
    float screenWidth, screenHeight;
    Shader* shader;
    std::vector<GLfloat> vert;
    void setSideData(int sideNum, int color);
public:
    glm::mat4 projection;
    cubeView(bool graphical_, float screenWidth_, float screenHeight_);
    ~cubeView();
    void display(const cubeModel& cube);
    void draw(const cubeModel& cube);
    void print(const cubeModel& cube);
    float getScreenWidth();
    float getScreenHeight();
    void setScreenWidth(float width_);
    void setScreenHeight(float height_);
    void updateProjection();
    void setProjection(glm::mat4 projection_);
};

#endif /* cubeView_hpp */
