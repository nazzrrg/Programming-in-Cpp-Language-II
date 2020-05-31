//
//  bigCube.hpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef bigCube_hpp
#define bigCube_hpp

#include <stdio.h>
#include <vector>
#include "smallCube.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <string>

class bigCube {
private:
    smallCube cubes[3][3][3]; // надо хранить //
public:
    GLuint texture; //
    std::string texturePath;
    bigCube(const std::string& texPath = "res/images/image2.png");
    ~bigCube();
    void drawCubes(glm::mat4& proj);
    void rotateSide(int sideNumber, int direction, float coef);
    Shader shader{"res/shaders/core.vs", "res/shaders/core.frag"};
    void saveFile(std::string filePath);
    void loadFile(std::string filePath); // после load надо init
    void newFile();
};

#endif /* bigCube_hpp */
