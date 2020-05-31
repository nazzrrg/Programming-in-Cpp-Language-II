//
//  cubeAPI.hpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 18.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef cubeAPI_hpp
#define cubeAPI_hpp

#include <stdio.h>
#include "bigCube.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <random>

static float lastX, lastY;
static float radius = 10.0f;
static float camX = sin(0), camY = cos(0), camZ = cos(0), dX = 0.0f, dY = 0.0f;
static bool firstMouse = true;
static float cameraRadius = 10.0f;
static float mouseSensetivity = 0.0005f;
static bool mouseMove = false;
static int selectedSide = 0;
static int rotDirection = 0;
static bool rotate = false;

class rubicksCube {
private:
    GLFWwindow* window;
    bigCube* cube;
    glm::mat4 projection = glm::mat4(1.0f);
    float delay = 100;
public:
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
        float xOffset, yOffset;
        if (mouseMove) {
            xOffset = lastX - xpos;
            yOffset = lastY - ypos;
            dX += xOffset*mouseSensetivity;
            dY += yOffset*mouseSensetivity;
            camX = sin(dX);
            camZ = cos(dX);
            camY = cos(dY);
        } else {
            lastX = xpos;
            lastY = ypos;
        }
    }
    static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
        cameraRadius += (float)yOffset*0.1;
//        std::cout << "yOffset: " << yOffset << std::endl;
        if (cameraRadius < 5.0f)
            cameraRadius = 5.0f;
        if (cameraRadius > 10.0f)
            cameraRadius = 10.0f;
    }
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            mouseMove = true;
        } else {
            mouseMove = false;
        }
    }
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (action == GLFW_PRESS) {
            switch (key) {
                case GLFW_KEY_0:
                    selectedSide = 0;
                    break;
                case GLFW_KEY_1:
                    selectedSide = 1;
                    break;
                case GLFW_KEY_2:
                    selectedSide = 2;
                    break;
                case GLFW_KEY_3:
                    selectedSide = 3;
                    break;
                case GLFW_KEY_4:
                    selectedSide = 4;
                    break;
                case GLFW_KEY_5:
                    selectedSide = 5;
                    break;
                case GLFW_KEY_6:
                    selectedSide = 6;
                    break;
                case GLFW_KEY_Q:
                    rotDirection = 2; // CCW
                    break;
                case GLFW_KEY_E:
                    rotDirection = 1; // CW
                    break;
                case GLFW_KEY_SPACE: {
                    if ((rotDirection == 2 || rotDirection == 1)&&(selectedSide > 0 && selectedSide <= 6))
                        rotate = true;
                    break;
                }
                case GLFW_KEY_ESCAPE: {
                    glfwSetWindowShouldClose(window, 1);
                    break;
                }
                default:
                    break;
            }
        }
    }
    rubicksCube(int delay_);
    ~rubicksCube();
    int run();
    int save();
    int screenWidth, screenHeight;
    void shuffle();
    int solve();
};

#endif /* cubeAPI_hpp */
