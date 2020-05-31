//
//  bigCube.cpp
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#include "bigCube.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "SOIL2/SOIL2.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <fstream>
#include <string>
#include <sstream>

bigCube::bigCube(const std::string& texPath) {
    texturePath = std::string(texPath);
    // Load and create a texture
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
    // Load, create texture and generate mipmaps
    unsigned char *image = SOIL_load_image(texturePath.c_str(), &width, &height, 0, SOIL_LOAD_RGBA); // перенести в апи
    // передать текстуру в конструктор
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                cubes[z][y][x].setCoords(x-1, y-1, z-1);
                cubes[z][y][x].setColor();
            }
        }
    }
}

bigCube::~bigCube() {
    glDeleteTextures(1, &texture);
}

void bigCube::drawCubes(glm::mat4& proj) {
    GLfloat timeStamp = glfwGetTime();
    for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                cubes[z][y][x].draw(texture, timeStamp, shader, proj);
            }
        }
    }
}

void bigCube::rotateSide(int sideNumber, int direction, float coef) {
    enum {USER_DIRECT_CW=1, USER_DIRECT_CCW=2};
    std::cout << "Rotate " << sideNumber <<' ';
    if (direction == USER_DIRECT_CCW) {
        std::cout << "Counter-ClockWise" << std::endl;
    } else {
        std::cout << "ClockWise" << std::endl;
    }
    switch (sideNumber) {
        case 1: { // OK CW by Z CCW by side
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < 3; ++i) {
                        if (cubes[k][j][i].getZ() == -1) {
                            if (direction == USER_DIRECT_CCW) {
                                cubes[k][j][i].rotZ(USER_DIRECT_CW);
                                cubes[k][j][i].setCoords(cubes[k][j][i].getY(),
                                                         -cubes[k][j][i].getX(),
                                                         cubes[k][j][i].getZ());
                            } else {
                                cubes[k][j][i].setCoords(-cubes[k][j][i].getY(),
                                                         cubes[k][j][i].getX(),
                                                         cubes[k][j][i].getZ());
                                cubes[k][j][i].rotZ(USER_DIRECT_CCW);
                            }
                        }
                    }
                }
            }
            break;
        }
        case 2: { // OK CCW by X CCW by side
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < 3; ++i) {
                        if (cubes[k][j][i].getX() == 1) {
                            if (direction == USER_DIRECT_CCW) {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getX(),
                                                         -cubes[k][j][i].getZ(),
                                                         cubes[k][j][i].getY());
                                cubes[k][j][i].rotX(USER_DIRECT_CCW);
                            } else {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getX(),
                                                         cubes[k][j][i].getZ(),
                                                         -cubes[k][j][i].getY());
                                cubes[k][j][i].rotX(USER_DIRECT_CW);
                            }
                        }
                    }
                }
            }
            break;
        }
        case 3: { // OK CCW by side CCW by Y
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < 3; ++i) {
                        if (cubes[k][j][i].getY() == 1) {
                            if (direction == USER_DIRECT_CCW) {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getZ(),
                                                         cubes[k][j][i].getY(),
                                                         -cubes[k][j][i].getX());
                                cubes[k][j][i].rotY(USER_DIRECT_CCW);
                            } else {
                                cubes[k][j][i].setCoords(-cubes[k][j][i].getZ(),
                                                         cubes[k][j][i].getY(),
                                                         cubes[k][j][i].getX());
                                cubes[k][j][i].rotY(USER_DIRECT_CW);
                            }
                        }
                    }
                }
            }
            break;
        }
        case 4: { // OK CCW by side CW by X
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < 3; ++i) {
                        if (cubes[k][j][i].getX() == -1) {
                            if (direction == USER_DIRECT_CCW) {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getX(),
                                                         cubes[k][j][i].getZ(),
                                                         -cubes[k][j][i].getY());
                                cubes[k][j][i].rotX(USER_DIRECT_CW);
                            } else {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getX(),
                                                         -cubes[k][j][i].getZ(),
                                                         cubes[k][j][i].getY());
                                cubes[k][j][i].rotX(USER_DIRECT_CCW);
                            }
                        }
                    }
                }
            }
            break;
        }
        case 5: { // OK CCW by side CW by Y
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < 3; ++i) {
                        if (cubes[k][j][i].getY() == -1) {
                            if (direction == USER_DIRECT_CCW) {
                                cubes[k][j][i].setCoords(-cubes[k][j][i].getZ(),
                                                         cubes[k][j][i].getY(),
                                                         cubes[k][j][i].getX());
                                cubes[k][j][i].rotY(USER_DIRECT_CW);
                            } else {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getZ(),
                                                         cubes[k][j][i].getY(),
                                                         -cubes[k][j][i].getX());
                                cubes[k][j][i].rotY(USER_DIRECT_CCW);
                            }
                        }
                    }
                }
            }
            break;
        }
        case 6: { // OK
            for (int k = 0; k < 3; ++k) {
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < 3; ++i) {
                        if (cubes[k][j][i].getZ() == 1) {
                            if (direction == USER_DIRECT_CCW) {
                                cubes[k][j][i].setCoords(-cubes[k][j][i].getY(),
                                                         cubes[k][j][i].getX(),
                                                         cubes[k][j][i].getZ());
                                cubes[k][j][i].rotY(USER_DIRECT_CCW);
                            } else {
                                cubes[k][j][i].setCoords(cubes[k][j][i].getY(),
                                                         -cubes[k][j][i].getX(),
                                                         cubes[k][j][i].getZ());
                                cubes[k][j][i].rotZ(USER_DIRECT_CW);
                            }
                        }
                    }
                }
            }
            break;
        }
        default:
            throw std::runtime_error("Error, unsupported rotation");
            break;
    }
}

void bigCube::saveFile(std::string filePath) {
    std::ofstream file(filePath.c_str(), std::ios::out);
    if (!file.is_open()) {
        throw std::runtime_error(std::string("Error opening file: ") + filePath);
    }
    std::stringstream buffer;
    for (int z = 0; z < 3; ++z) {
        for (int y = 0; y < 3; ++y) {
            for (int x = 0; x < 3; ++x) {
                buffer << std::to_string(z) << ' ' << std::to_string(y) << ' ' << std::to_string(x) << '\t';
                    
                for (int i = 0; i < 6; ++i) {
                    buffer << std::to_string(cubes[z][y][x].getColor(i)) << ' ';
                }
                
                buffer << '\n';
            }
        }
    }
    buffer << '\0';
    file << buffer.rdbuf();
    file.flush();
    file.close();
}

void bigCube::loadFile(std::string filePath) {
    std::ifstream file(filePath.c_str(), std::ios::in);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    for (int i = 0; i < 27; ++i) {
        std::string stringX, stringY, stringZ;
        buffer >> stringZ >> stringY >> stringX;
        int x = std::stoi(stringX), y = std::stoi(stringY), z = std::stoi(stringZ);
        std::string part;
        for (int k = 0; k < 6; ++k) {
            buffer >> part;
            int j = std::stoi(part);
            cubes[z][y][x].setColor(k, j);
        }
    }
}
