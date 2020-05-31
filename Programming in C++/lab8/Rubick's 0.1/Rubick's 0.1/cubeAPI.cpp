//
//  cubeAPI.cpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 18.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//
#include "cubeAPI.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <fstream>
#include <chrono>
#include <thread>
#include <random>
#include <time.h>

rubicksCube::rubicksCube(int delay_) {
    delay = delay_;
    const GLint WIDTH = 800, HEIGHT = 600;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,  3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    window = glfwCreateWindow(WIDTH, HEIGHT, "Rubick's cube 0.1 alpha by nazzrrg", nullptr, nullptr);
    
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    
    if (window == nullptr) {
        std::cerr << "Failed to create GL window" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to create GL window");
    }
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        throw std::runtime_error("Failed to initialize GLEW");
    }
        
    //define viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);
    
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    cube = new bigCube();

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetScrollCallback(window, scrollCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetKeyCallback(window, keyCallback);
//    cube->saveFile("/Users/nazzrrg/Git/Programming-in-Cpp-Language-II/Programming in C++/lab8/Rubick's 0.1/Rubick's 0.1/myCube.txt");
//    cube->loadFile("/Users/nazzrrg/Git/Programming-in-Cpp-Language-II/Programming in C++/lab8/Rubick's 0.1/Rubick's 0.1/myCube1.txt");
//    shuffle();
//    cube->saveFile("/Users/nazzrrg/Git/Programming-in-Cpp-Language-II/Programming in C++/lab8/Rubick's 0.1/Rubick's 0.1/myCube2.txt");
}

rubicksCube::~rubicksCube() {
    delete cube;
}

int rubicksCube::run() {
    // Game Loop
//    int i = 0;
    GLfloat timeStamp = 0;
    GLfloat timeDelta, timeAccum;
    while (!glfwWindowShouldClose(window)) {
        
        // Check for corresponding game events
        glfwPollEvents();
        timeAccum += glfwGetTime() - timeStamp;
        timeStamp = glfwGetTime();
        if (timeAccum >= delay) {
            // Do some shanges
            
            timeAccum = 0;
        }
        // Render
        projection = glm::perspective(45.0f, (GLfloat)screenWidth/screenHeight, 0.1f, 2000.0f) * glm::lookAt(glm::vec3(camX*cameraRadius, camY*cameraRadius, camZ*cameraRadius), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        
        // Clear the color buffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Draw
        
        cube->drawCubes(projection);
        
        if (rotate) {
            cube -> rotateSide(selectedSide, rotDirection, 1);
            rotate = false;
        }
        
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    
    return 0;
}

void rubicksCube::shuffle() {
    std::random_device rd;
    std::mt19937 mt(rd());
    int count = mt()% 500;
    for (int i = 0; i < count; ++i) {
        std::mt19937 mt1(rd());
        int number = mt1();
        cube->rotateSide(i%6+1, number%2+1, 1);
        std::cout << number << std::endl;
    }
    std::cout << "Total operations: " << count << std::endl;
}
