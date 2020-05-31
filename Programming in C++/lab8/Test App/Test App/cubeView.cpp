//
//  cubeView.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "cubeView.hpp"
#include <OpenGL/gl3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

cubeView::cubeView(bool graphical_, int screenWidth_, int screenHeight_) {
    graphical = graphical_;
    if (graphical) {
        glEnable(GL_DEPTH_TEST);
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        int width, height;

        // ===================
        // Texture
        // ===================
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        // Set our texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // Set texture filtering
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        unsigned char *image = SOIL_load_image("res/images/image2.png", &width, &height, 0, SOIL_LOAD_RGBA);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);
        SOIL_free_image_data(image);
        glBindTexture(GL_TEXTURE_2D, 0);
        
        screenWidth = screenWidth_;
        screenHeight = screenHeight_;
        
        vert.resize(30);
        
        projection = glm::perspective(45.0f, (GLfloat)screenWidth/screenHeight, 0.1f, 2000.0f) * glm::lookAt(glm::vec3(6.0, 6.0, 6.0), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    }
}

cubeView::~cubeView() {
    glDeleteTextures(1, &texture);
}

int cubeView::getScreenWidth() {
    return screenWidth;
}

int cubeView::getScreenHeight() {
    return screenHeight;
}

void cubeView::display(const cubeModel& cube) {
    if (graphical) {
        this->draw(cube);
    } else {
        this->print(cube);
    }
}

void cubeView::print(const cubeModel& cube) {
    
}

void cubeView::setSideData(int sideNum, int color) {
    switch (sideNum) { // set coords
        case 0: { // cube bottom
            vert = {
                -0.5f, -0.5f, -0.5f,    0, 0, // Bottom Left
                -0.5f,  0.5f, -0.5f,    0, 0, // Bottom Right
                 0.5f,  0.5f, -0.5f,    0, 0, // Top Right
                -0.5f, -0.5f, -0.5f,    0, 0, // Bottom Left
                 0.5f, -0.5f, -0.5f,    0, 0, // Top Left
                 0.5f,  0.5f, -0.5f,    0, 0  // Top Right
            };
            break;
        }
        case 1: { // cube front
            vert = {
                 0.5f, -0.5f, -0.5f,    0, 0, // Bottom Left
                 0.5f,  0.5f, -0.5f,    0, 0, // Bottom Right
                 0.5f,  0.5f,  0.5f,    0, 0, // Top Right
                 0.5f, -0.5f, -0.5f,    0, 0, // Bottom Left
                 0.5f, -0.5f,  0.5f,    0, 0, // Top Left
                 0.5f,  0.5f,  0.5f,    0, 0  // Top Right
            };
            break;
        }
        case 2: { // cube right
            vert = {
                 0.5f,  0.5f, -0.5f,    0, 0, // Bottom Left
                -0.5f,  0.5f, -0.5f,    0, 0, // Bottom Right
                -0.5f,  0.5f,  0.5f,    0, 0, // Top Right
                 0.5f,  0.5f, -0.5f,    0, 0, // Bottom Left
                 0.5f,  0.5f,  0.5f,    0, 0, // Top Left
                -0.5f,  0.5f,  0.5f,    0, 0  // Top Right
            };
            break;
        }
        case 3: { // cube back
            vert = {
                -0.5f,  0.5f, -0.5f,    0, 0, // Bottom Left
                -0.5f, -0.5f, -0.5f,    0, 0, // Bottom Right
                -0.5f, -0.5f,  0.5f,    0, 0, // Top Right
                -0.5f,  0.5f, -0.5f,    0, 0, // Bottom Left
                -0.5f,  0.5f,  0.5f,    0, 0, // Top Left
                -0.5f, -0.5f,  0.5f,    0, 0  // Top Right
            };
            break;
        }
        case 4: { // cube left
            vert = {
                -0.5f, -0.5f, -0.5f,    0, 0, // Bottom Left
                 0.5f, -0.5f, -0.5f,    0, 0, // Bottom Right
                 0.5f, -0.5f,  0.5f,    0, 0, // Top Right
                -0.5f, -0.5f, -0.5f,    0, 0, // Bottom Left
                 0.5f, -0.5f,  0.5f,    0, 0, // Top Left
                 0.5f, -0.5f,  0.5f,    0, 0  // Top Right
            };
            break;
        }
        case 5:{
            vert = {
                 0.5f, -0.5f,  0.5f,    0, 0, // Bottom Left
                 0.5f,  0.5f,  0.5f,    0, 0, // Bottom Right
                -0.5f,  0.5f,  0.5f,    0, 0, // Top Right
                 0.5f, -0.5f,  0.5f,    0, 0, // Bottom Left
                -0.5f, -0.5f,  0.5f,    0, 0, // Top Left
                -0.5f,  0.5f,  0.5f,    0, 0  // Top Right
            };
            break;
        }
        default:
            break;
    }

    vert[3]  = color/7.0;           vert[4]  = 0.0; // Bottom Left
    vert[8]  = (color + 1.0)/7.0;   vert[9]  = 0.0; // Bottom Right
    vert[13] = (color + 1.0)/7.0;   vert[14] = 1.0; // Top Right
    vert[18] = color/7.0;           vert[19] = 0.0; // Bottom Left
    vert[23] = color/7.0;           vert[24] = 1.0; // Top Left
    vert[28] = (color + 1.0)/7.0;   vert[29] = 1.0; // Top Right
}


void cubeView::draw(const cubeModel& cube) {
//    projection = glm::perspective(45.0f, (GLfloat)screenWidth/screenHeight, 0.1f, 2000.0f) * glm::lookAt(glm::vec3(camX*cameraRadius, camY*cameraRadius, camZ*cameraRadius), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for (auto item : cube.cubes) {
        for (int i = 0; i < 6; ++i) {
            this->setSideData(i, item.getColor(i));
            
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
            
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture);
            glUniform1i(glGetUniformLocation(shader.Program, "ourTexture"), 0);
                
            glm::mat4 view = glm::mat4(1.0f);
            view = glm::translate(view, glm::vec3(item.getX(), item.getY(), item.getZ()));
                
            GLint viewLoc = glGetUniformLocation(shader.Program, "view");
            GLint projLoc = glGetUniformLocation(shader.Program, "projection");
                        
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
            glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
            
            shader.Use();
            
            // Draw container
            glDrawArrays(GL_TRIANGLES, 0, 6);
            glBindVertexArray(0);
            glDeleteBuffers(1, &VBO);
            glDeleteVertexArrays(1, &VAO);
        }
    }
}
