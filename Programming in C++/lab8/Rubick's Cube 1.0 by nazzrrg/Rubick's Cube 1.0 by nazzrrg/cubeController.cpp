//
//  cubeController.cpp
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//
#include "cubeController.hpp"
#include <random>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "cubeView.hpp"
#include "Shader.hpp"
#include "smallCubeModel.hpp"

cubeController::cubeController() {}
cubeController::~cubeController() {}

void cubeController::shuffle(cubeModel& cube) {
    reset(cube);
    std::random_device rd;
    std::mt19937 mt(rd());
    int count = mt()% 50 + 50;
    for (int i = 0; i < count; ++i) {
        std::mt19937 mt1(rd());
        int number = mt1();
        int side = i%6+1;
        int direction = abs(number)%2+1;
        cube.rotateSide(side, direction);
    }
}

void cubeController::rotate(cubeModel& cube, int side, int direction) {
    cube.rotateSide(side, direction);
}

void cubeController::moveCam(cubeView &cube, float x0, float y0, float x, float y) {
    float xOffset, yOffset;
    const float mouseSensetivity = 0.0005f;
    xOffset = x0 - x;
    yOffset = y0 - y;
    dX += xOffset*mouseSensetivity;
    dY += yOffset*mouseSensetivity;
    camX = sin(dX);
    camZ = cos(dX);
    camY = cos(dY);
    float screenWidth = cube.getScreenWidth();
    float screenHeight = cube.getScreenHeight();
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)screenWidth/screenHeight, 0.1f, 2000.0f) * glm::lookAt(glm::vec3(camX*cameraRadius, camY*cameraRadius, camZ*cameraRadius), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    cube.setProjection(projection);
}

void cubeController::zoomCam(cubeView &cube, float delta) {
    cameraRadius += delta;
    
    if (cameraRadius <= 3.0) {
        cameraRadius = 3.0;
    } else if (cameraRadius >= 10.0) {
        cameraRadius = 10.0;
    }
    
    float screenWidth = cube.getScreenWidth();
    float screenHeight = cube.getScreenHeight();
    glm::mat4 projection = glm::perspective(45.0f, (GLfloat)screenWidth/screenHeight, 0.1f, 2000.0f) * glm::lookAt(glm::vec3(camX*cameraRadius, camY*cameraRadius, camZ*cameraRadius), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    cube.setProjection(projection);
}

void cubeController::solve(cubeModel &cube) { //Gr Bl Wh Ye Or R
    moooves.clear();

    smallCubeModel cubie;
    if (!solveFinishFlag) {
    cubie = cube.cubes[5];
        int x = cubie.getX(), y = cubie.getY(), z = cubie.getZ();
        if (x == 1 && y == 0 && z == -1) {
            if (cubie.getColor(1) == 1 && cubie.getColor(0) == 0) {
//                break;
            } else if (cubie.getColor(1) == 0 && cubie.getColor(0) == 1) {
                moooves = moooves + "bOYobb";return;
            }
        }
        if (x == 1 && y == 0 && z == 1) {
            if (cubie.getColor(1) == 0 && cubie.getColor(5) == 1) {
                moooves = moooves + "BOYobb";return;
            } else if (cubie.getColor(1) == 1 && cubie.getColor(5) == 0) {
                moooves = moooves + "BB";return;
            }
        }
        if (x == -1 && y == 0 && z == -1) {
            if (cubie.getColor(3) == 0 && cubie.getColor(0) == 1) {
                moooves = moooves + "GGYYBOYobb";return;
            } else if (cubie.getColor(3) == 1 && cubie.getColor(0) == 0) {
                moooves = moooves + "GGYYBB";return;
            }
        }
        if (x == -1 && y == 0 && z == 1) {
            if (cubie.getColor(3) == 0 && cubie.getColor(5) == 1) {
                moooves = moooves + "YYBOYobb";return;
            } else if (cubie.getColor(3) == 1 && cubie.getColor(5) == 0) {
                moooves = moooves + "YYBB";return;
            }
        }

        if (x == 0 && y == 1 && z == -1) {
            if (cubie.getColor(0) == 1 && cubie.getColor(2) == 0) {
                moooves = moooves + "OOYBOYobb";return;
            } else if (cubie.getColor(0) == 0 && cubie.getColor(2) == 1) {
                moooves = moooves + "OOYBB";return;
            }
        }
        if (x == 0 && y == 1 && z == 1) {
            if (cubie.getColor(2)==0 && cubie.getColor(5) == 1) {
                moooves = moooves + "YBOYobb";return;
            } else if (cubie.getColor(2)==1 && cubie.getColor(5) == 0) {
                moooves = moooves + "YBB";return;
            }
        }
        if (x == 0 && y == -1 && z == -1) {
            if (cubie.getColor(0) == 1 && cubie.getColor(4) == 0) {
                moooves = moooves + "RRyBOYobb";return;
            } else if (cubie.getColor(0) == 0 && cubie.getColor(4) == 1) {
                moooves = moooves + "RRyBB";return;
            }
        }
        if (x == 0 && y == -1 && z == 1) {
            if (cubie.getColor(4)==0 && cubie.getColor(5) == 1) {
                moooves = moooves + "yBOYobb";return;
            } else if (cubie.getColor(4)==1 && cubie.getColor(5) == 0) {
                moooves = moooves + "yBB";return;
            }
        }

        if (x == 1 && y == 1 && z == 0) {
            if (cubie.getColor(1) == 0 && cubie.getColor(2) == 1) {
                moooves = moooves + "OYoBB";return;
            } else if (cubie.getColor(1) == 1 && cubie.getColor(2) == 0) {
                moooves = moooves + "B";return;
            }
        }
        if (x == -1 && y == 1 && z == 0) {
            if (cubie.getColor(2) == 0 && cubie.getColor(3)==1) {
                moooves = moooves + "GYgYBB";return;
            } else if (cubie.getColor(2) == 1 && cubie.getColor(3)==0) {
                moooves = moooves + "oYOBB";
                return;
            }
        }
        if (x == 1 && y == -1 && z == 0) {
            if (cubie.getColor(1) == 0 && cubie.getColor(4) == 1) {
                moooves = moooves + "ryRBB";return;
            } else if (cubie.getColor(1) == 1 && cubie.getColor(4) == 0) {
                moooves = moooves + "b";return;
            }
        }
        if (x == -1 && y == -1 && z == 0) {
            if (cubie.getColor(4) == 0 && cubie.getColor(3)==1) {
                moooves = moooves + "gYGYBB";return;
            } else if (cubie.getColor(4) == 1 && cubie.getColor(3)==0) {
                moooves = moooves + "RyrBB";return;
            }
        }
//    }

//    for (auto cubie : cube.cubes) { // Orange-White
    cubie = cube.cubes[7];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
        if (x == 1 && y == 0 && z == -1) {
            if(cubie.getColor(0)==2&&cubie.getColor(1)==0) {
                moooves=moooves+"BByOGYgoo";return;
            }else if (cubie.getColor(0)==0&&cubie.getColor(1)==2) {
                moooves=moooves+"BByOO";return;
            }
        }//ok
        if (x == 1 && y == 0 && z == 1) {
            if(cubie.getColor(1)==0&&cubie.getColor(5)==2) {
                moooves=moooves+"yOGYgoo";return;
            } else if (cubie.getColor(1)==2&&cubie.getColor(5)==0) {
                moooves=moooves+"yOO";return;
            }
        }//ok
        if (x == -1 && y == 0 && z == -1) {
            if(cubie.getColor(0)==2&&cubie.getColor(3)==0) {
                moooves=moooves+"GGYOGYgoo";return;
            }else if (cubie.getColor(0)==0&&cubie.getColor(3)==2) {
                moooves=moooves+"GGYOO";return;
            }
        }
        if (x == -1 && y == 0 && z == 1) {
            if(cubie.getColor(3)==0&&cubie.getColor(5)==2) {
                moooves=moooves+"YOGYgoo";return;
            } else if (cubie.getColor(3)==2&&cubie.getColor(5)==0) {
                moooves=moooves+"YOO";return;
            }
        }//ok

        if (x == 0 && y == 1 && z == -1) {
            if (cubie.getColor(2) == 0 && cubie.getColor(0) == 2) {
                moooves = moooves + "oGYgoo";return;
            } else if (cubie.getColor(2) == 2 && cubie.getColor(0) == 0) {
//                break;
            }
        }//ok
        if (x == 0 && y == 1 && z == 1) {
            if (cubie.getColor(2) == 0 && cubie.getColor(5)==2) {
                moooves=moooves+"OGYgoo";return;
            } else if (cubie.getColor(2) == 2 && cubie.getColor(5)==0) {
                moooves=moooves+"OO";return;
            }
        }//ok
        if (x == 0 && y == -1 && z == 1) {
            if (cubie.getColor(4)==0&&cubie.getColor(5)==2) {
                moooves=moooves+"YYOGYgoo";return;
            } else if (cubie.getColor(4)==2&&cubie.getColor(5)==0) {
                moooves=moooves+"YYOO";return;
            }
        }//ok
        if (x == 0 && y == -1 && z == -1) {
            if (cubie.getColor(4) == 0 && cubie.getColor(0)==2) {
                moooves=moooves+"RRYYOGYgoo";return;
            } else if (cubie.getColor(4) == 2 && cubie.getColor(0)==0) {
                moooves=moooves+"RRYYOO";return;
            }
        }//ok

        if (x == 1 && y == 1 && z == 0) {
            if(cubie.getColor(1)==2&&cubie.getColor(2)==0) {
                moooves=moooves+"byBOO";return;
            } else if (cubie.getColor(1)==0&&cubie.getColor(2)==2) {
                moooves=moooves+"o";return;
            }
        }//ok
        if (x == -1 && y == 1 && z == 0) {
            if(cubie.getColor(3)==2&&cubie.getColor(2)==0) {
                moooves=moooves+"GYgOO";return;
            }else if(cubie.getColor(3)==0&&cubie.getColor(2)==2) {
                moooves=moooves+"O";return;
            }
        }//ok
        if (x == 1 && y == -1 && z == 0) {
            if(cubie.getColor(1)==2&&cubie.getColor(4)==0) {
                moooves=moooves+"BybOO";return;
            } else if (cubie.getColor(1)==0&&cubie.getColor(4)==2) {
                moooves=moooves+"BybOGYgoo";return;
            }
        }//ok
        if (x == -1 && y == -1 && z == 0) {
            if(cubie.getColor(4)==0&&cubie.getColor(3)==2) {
                moooves=moooves+"gYGOO";return;
            } else if (cubie.getColor(4)==2&&cubie.getColor(3)==0) {
                moooves=moooves+"gYGOGYgoo";return;
            }
        }
//    }

//    for (auto cubie : cube.cubes) { // Red-White 4-0
    cubie = cube.cubes[1];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
        if (x == 1 && y == 0 && z == -1) {
            if(cubie.getColor(1)== 0 &&cubie.getColor(0)==4) {
                moooves=moooves+"BR";return;
            }else if (cubie.getColor(1)== 4 &&cubie.getColor(0)==0) {
                moooves=moooves+"BBYRR";return;
            }
        }//ok
        if (x == 1 && y == 0 && z == 1) {
            if(cubie.getColor(1)== 0 &&cubie.getColor(5)==4) {
                moooves=moooves+"YRBYbrr";return; // RBYbrr
            }else if (cubie.getColor(1)== 4 &&cubie.getColor(5)==0) {
                moooves=moooves+"Yrr";return;
            }
        }//ok
        if (x == -1 && y == 0 && z == -1) {
            if(cubie.getColor(3)== 0 &&cubie.getColor(0)==4) {
                moooves=moooves+"ggyRBYbrr";return;
            }else if (cubie.getColor(3)== 4 &&cubie.getColor(0)==0) {
                moooves=moooves+"ggyRR";return;
            }
        }//ok
        if (x == -1 && y == 0 && z == 1) {
            if(cubie.getColor(3)== 0 &&cubie.getColor(5)==4) {
                moooves=moooves+"yRBYbrr";return; // RBYbrr
            }else if (cubie.getColor(3)== 4 &&cubie.getColor(5)==0) {
                moooves=moooves+"yrr";return;
            }
        }//ok

        if (x == 0 && y == 1 && z == -1) {
            if(cubie.getColor(0)== 4 &&cubie.getColor(2)== 0) {
                moooves=moooves+"ooyyRBYbrr";return; // RBYbrr
            }else if (cubie.getColor(0)== 0 &&cubie.getColor(2)== 4) {
                moooves=moooves+"ooyyrr";return;
            }
        }//
        if (x == 0 && y == 1 && z == 1) {
            if(cubie.getColor(2)== 0 &&cubie.getColor(5)== 4) {
                moooves=moooves+"yyRBYbrr";return;
            }else if (cubie.getColor(2)== 4 &&cubie.getColor(5)== 0) {
                moooves=moooves+"yyrr";return;
            }
        }//ok
        if (x == 0 && y == -1 && z == -1) {
            if(cubie.getColor(0)== 4 &&cubie.getColor(4)== 0) {
                moooves=moooves+"rBYbrr";return; // RBYbrr
            }else if (cubie.getColor(0)== 0 &&cubie.getColor(4)== 4) {
//                  break;
            }
        }//ok
        if (x == 0 && y == -1 && z == 1) {
            if(cubie.getColor(4)== 0 &&cubie.getColor(5)== 4) {
                moooves=moooves+"RBYbrr";return; // RBYbrr
            }else if (cubie.getColor(4)== 4 &&cubie.getColor(5)== 0) {
                moooves=moooves+"rr";return;
            }
        }//ok

        if (x == 1 && y == 1 && z == 0) {
            if(cubie.getColor(1)== 0 &&cubie.getColor(2)==4) {
                moooves=moooves+"bYBRBYbrr";return;
            }else if (cubie.getColor(1)== 4 &&cubie.getColor(2)==0) {
                moooves=moooves+"bYBrr";return;
            }
        }
        if (x == -1 && y == 1 && z == 0) {
            if(cubie.getColor(2)== 4 &&cubie.getColor(3)==0) {
                moooves=moooves+"oyyOrr";return;
            }else if (cubie.getColor(2)== 0 &&cubie.getColor(3)==4) {
                moooves=moooves+"oyyORBYbrr";return;
            }
        }
        if (x == 1 && y == -1 && z == 0) {
            if(cubie.getColor(1)== 4 &&cubie.getColor(4)==0) {
                moooves=moooves+"BYbrr";return;
            }else if (cubie.getColor(1)== 0 &&cubie.getColor(4)==4) {
                moooves=moooves+"R";return;
            }
        }
        if (x == -1 && y == -1 && z == 0) {
            if(cubie.getColor(3)== 4 &&cubie.getColor(4)==0) {
                moooves=moooves+"gyGrr";return;
            }else if (cubie.getColor(3)== 0 &&cubie.getColor(4)==4) {
                moooves=moooves+"r";return;
            }
        }
//    }

//    for (auto cubie : cube.cubes) { // Green-White 3-0
    cubie = cube.cubes[3];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
        if (x == 1 && y == 0 && z == 1) {
            if(cubie.getColor(1)== 0 &&cubie.getColor(5)==3) {
                moooves=moooves+"yyGRYrgg";return; //
            }else if (cubie.getColor(1)== 3 &&cubie.getColor(5)==0) {
                moooves=moooves+"yygg";return;
            }
        }//ok
        if (x == -1 && y == 0 && z == -1) {
            if(cubie.getColor(3)== 0 &&cubie.getColor(0)==3) {
                moooves=moooves+"gRYrgg";return;
            }else if (cubie.getColor(3)== 3 &&cubie.getColor(0)==0) {
//                break;
            }
        }//ok
        if (x == -1 && y == 0 && z == 1) {
            if(cubie.getColor(3)== 0 &&cubie.getColor(5)==3) {
                moooves=moooves+"GRYrgg";return; // GRYrgg
            }else if (cubie.getColor(3)== 3 &&cubie.getColor(5)==0) {
                moooves=moooves+"gg";return;
            }
        }//ok
        if (x == 0 && y == 1 && z == 1) {
            if(cubie.getColor(2)== 0 &&cubie.getColor(5)== 3) {
                moooves=moooves+"yGRYrgg";return;
            }else if (cubie.getColor(2)== 3 &&cubie.getColor(5)== 0) {
                moooves=moooves+"ygg";return;
            }
        }//ok
        if (x == 0 && y == -1 && z == 1) {
            if(cubie.getColor(4)== 0 &&cubie.getColor(5)== 3) {
                moooves=moooves+"YGRYrgg";return; //
            }else if (cubie.getColor(4)== 3 &&cubie.getColor(5)== 0) {
                moooves=moooves+"Ygg";return;
            }
        }//ok

        if (x == 1 && y == 1 && z == 0) {
            if(cubie.getColor(1)== 0 &&cubie.getColor(2)==3) {
                moooves=moooves+"Oyogg";return;
            }else if (cubie.getColor(1)== 3 &&cubie.getColor(2)==0) {
                moooves=moooves+"OyoGRYrgg";return;
            }
        }//ok
        if (x == -1 && y == 1 && z == 0) {
            if(cubie.getColor(2)== 3 &&cubie.getColor(3)==0) {
                moooves=moooves+"oyyOrr";return;
            }else if (cubie.getColor(2)== 0 &&cubie.getColor(3)==3) {
                moooves=moooves+"oyOgg";return;
            }
        }//ok
        if (x == 1 && y == -1 && z == 0) {
            if(cubie.getColor(1)== 3 &&cubie.getColor(4)==0) {
                moooves=moooves+"rYRGRYrgg";return;
            }else if (cubie.getColor(1)== 0 &&cubie.getColor(4)==3) {
                moooves=moooves+"rYRgg";return;
            }
        }
        if (x == -1 && y == -1 && z == 0) {
            if(cubie.getColor(3)== 3 &&cubie.getColor(4)==0) {
                moooves=moooves+"G";return;
            }else if (cubie.getColor(3)== 0 &&cubie.getColor(4)==3) {
                moooves=moooves+"RYrgg";return;
            }
        }//ok
//    }
    
//    for (auto cubie : cube.cubes) { // W-B-O
    cubie = cube.cubes[8];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
        if (x==1 && y==1 && z==1) {
            if (cubie.getColor(1)==0&&cubie.getColor(2)==2&&cubie.getColor(5)==1) {
                moooves = moooves + "OYoyOYoyOYoyOYoyOYoy"; return;
            }
            if (cubie.getColor(1)==2&&cubie.getColor(2)==1&&cubie.getColor(5)==0) {
                moooves = moooves + "OYoyOYoyOYoy"; return;
            }
            if (cubie.getColor(1)==1&&cubie.getColor(2)==0&&cubie.getColor(5)==2) {
                moooves = moooves + "OYoy"; return;
            }
        } else if (x==1&&y==1&&z==-1) {
            if (cubie.getColor(1)==0&&cubie.getColor(2)==1&&cubie.getColor(0)==2) {
                moooves = moooves + "OYoyOYoyOYoyOYoy"; return;
            }
            if (cubie.getColor(1)==2&&cubie.getColor(2)==0&&cubie.getColor(0)==1) {
                moooves = moooves + "OYoyOYoy"; return;
            }
            if (cubie.getColor(1)==1&&cubie.getColor(2)==2&&cubie.getColor(0)==0) {
//                break;
            }
        } else if (z==1) {
            moooves = moooves + "Y"; return;
        } else {
            if (x==1&&y==-1) {
                moooves = moooves+"BYby"; return;
            }
            if (x==-1&&y==1) {
                moooves=moooves+"GYgy";return;
            }
            if (x==-1&&y==-1) {
                moooves=moooves+"RYry";return;
            }
        }
//    }
    cubie = cube.cubes[6];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==-1 && y==1 && z==1) {
                if (cubie.getColor(2)==0&&cubie.getColor(3)==3&&cubie.getColor(5)==2) {
                    moooves = moooves + "GYgyGYgyGYgyGYgyGYgy"; return;
                }
                if (cubie.getColor(2)==3&&cubie.getColor(3)==2&&cubie.getColor(5)==0) {
                    moooves = moooves + "GYgyGYgyGYgy"; return;
                }
                if (cubie.getColor(2)==2&&cubie.getColor(3)==0&&cubie.getColor(5)==3) {
                    moooves = moooves + "GYgy"; return;
                }
    } else if (x==-1&&y==1&&z==-1) {
                if (cubie.getColor(2)==0&&cubie.getColor(3)==2&&cubie.getColor(0)==3) {
                    moooves = moooves + "GYgyGYgyGYgyGYgy"; return;
                }
                if (cubie.getColor(2)==3&&cubie.getColor(3)==0&&cubie.getColor(0)==2) {
                    moooves = moooves + "GYgyGYgy"; return;
                }
                if (cubie.getColor(2)==2&&cubie.getColor(3)==3&&cubie.getColor(0)==0) {
    //                break;
                }
    } else if (z==1) {
            moooves = moooves + "Y"; return;
    } else {
        if (x==1&&y==-1) {
            moooves = moooves+"BYby"; return;
        }
        if (x==-1&&y==-1) {
            moooves=moooves+"RYry";return;
        }
    }
    
    
    cubie=cube.cubes[2];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==1 && y==-1 && z==1) {
                if (cubie.getColor(4)==0&&cubie.getColor(1)==1&&cubie.getColor(5)==4) {
                    moooves = moooves + "BYbyBYbyBYbyBYbyBYby"; return;//BYby
                }
                if (cubie.getColor(4)==1&&cubie.getColor(1)==4&&cubie.getColor(5)==0) {
                    moooves = moooves + "BYbyBYbyBYby"; return;
                }
                if (cubie.getColor(4)==4&&cubie.getColor(1)==0&&cubie.getColor(5)==1) {
                    moooves = moooves + "BYby"; return;
                }
    } else if (x==1&&y==-1&&z==-1) {
                if (cubie.getColor(4)==0&&cubie.getColor(1)==4&&cubie.getColor(0)==1) {
                    moooves = moooves + "BYbyBYbyBYbyBYby"; return;
                }
                if (cubie.getColor(4)==1&&cubie.getColor(1)==0&&cubie.getColor(0)==4) {
                    moooves = moooves + "BYbyBYby"; return;
                }
                if (cubie.getColor(4)==4&&cubie.getColor(1)==1&&cubie.getColor(0)==0) {
    //                break;
                }
    } else if (z==1) {
            moooves = moooves + "Y"; return;
    } else {
        if (x==-1&&y==-1) {
            moooves=moooves+"RYry"; return;
        }
    }

    cubie=cube.cubes[0];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==-1 && y==-1 && z==1) {
                if (cubie.getColor(3)==0&&cubie.getColor(4)==4&&cubie.getColor(5)==3) {
                    moooves = moooves + "RYryRYryRYryRYryRYry"; return;//RYry
                }
                if (cubie.getColor(3)==4&&cubie.getColor(4)==3&&cubie.getColor(5)==0) {
                    moooves = moooves + "RYryRYryRYry"; return;
                }
                if (cubie.getColor(3)==3&&cubie.getColor(4)==0&&cubie.getColor(5)==4) {
                    moooves = moooves + "RYry"; return;
                }
    } else if (x==-1&&y==-1&&z==-1) {
                if (cubie.getColor(3)==0&&cubie.getColor(4)==3&&cubie.getColor(0)==4) {
                    moooves = moooves + "RYryRYryRYryRYry"; return;
                }
                if (cubie.getColor(3)==4&&cubie.getColor(4)==0&&cubie.getColor(0)==3) {
                    moooves = moooves + "RYryRYry"; return;
                }
                if (cubie.getColor(3)==3&&cubie.getColor(4)==4&&cubie.getColor(0)==0) {
    //                break;
                }
    } else {
            moooves = moooves + "Y"; return;
    }
    
    cubie=cube.cubes[17];//Gr-Or
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (z==1) {
        if (cubie.getColor(1)==1) {
            moooves=moooves+"YOyoybYB";return;
        } else if (cubie.getColor(2)==2) {
            moooves=moooves+"ybYBYOyo";return;
        } else {
            moooves = moooves + "Y"; return;
        }
    } else if (z==0) {
        if (x==1&&y==1) {
            if (cubie.getColor(1)==1&&cubie.getColor(2)==2){
                
            } else {
                 moooves=moooves+"YOyoybYB";return;
            }
        } else if (x==1&&y==-1) {
            moooves=moooves+"YBybyrYR";return;
        } else if (x==-1&&y==-1) {
            moooves=moooves+"YRyrygYG";return;
        } else if (x==-1&&y==1) {
            moooves=moooves+"YGygyoYO";return;
        }
    }
    
    cubie=cube.cubes[15];//Bl-Or
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (z==1) {
        if (cubie.getColor(2)==2) {
            moooves=moooves+"YGygyoYO";return;
        } else if (cubie.getColor(3)==3) {
            moooves=moooves+"yoYOYGyg";return;
        } else {
            moooves = moooves + "Y"; return;
        }
    } else if (z==0) {
        if (x==-1&&y==1) {
            if (cubie.getColor(2)==2&&cubie.getColor(3)==3){
                
            } else {
                 moooves=moooves+"YGygyoYO";return;
            }
        } else if (x==1&&y==-1) {
            moooves=moooves+"YBybyrYR";return;
        } else if (x==-1&&y==-1) {
            moooves=moooves+"YRyrygYG";return;
        }
    }
    
    cubie=cube.cubes[11];//Gr-Or
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (z==1) {
        if (cubie.getColor(1)==1) {
            moooves=moooves+"yrYRYByb";return;
        } else if (cubie.getColor(4)==4) {
            moooves=moooves+"YBybyrYR";return;
        } else {
            moooves = moooves + "Y"; return;
        }
    } else if (z==0) {
        if (x==1&&y==-1) {
            if (cubie.getColor(1)==1&&cubie.getColor(4)==4){
                
            } else {
                 moooves=moooves+"YBybyrYR";return;
            }
        } else if (x==-1&&y==-1) {
            moooves=moooves+"YRyrygYG";return;
        }
    }
    
    cubie=cube.cubes[9];//Gr-Or
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (z==1) {
        if (cubie.getColor(3)==3) {
            moooves=moooves+"YRyrygYG";return;
        } else if (cubie.getColor(4)==4) {
            moooves=moooves+"ygYGYRyr";return;
        } else {
            moooves = moooves + "Y"; return;
        }
    } else if (z==0) {
        if (x==-1&&y==-1) {
            if (cubie.getColor(3)==3&&cubie.getColor(4)==4){
                
            } else {
                 moooves=moooves+"YRyrygYG";return;
            }
        }
    }
    std::vector<int> v(9);
    for (int i = 18; i < 27; ++i) {
        cubie = cube.cubes[i];
        v[i-18]=cubie.getColor(5)==5 ? 1 : 0;
    }
    if (v[1]==1&&v[3]==1&&v[4]==1&&v[5]==1&&v[7]==1) {
        
    } else if (v[3]==1&&v[4]==1&&v[5]==1) { // line x
        moooves=moooves+"YBOYoyb"; return;
    } else if (v[1]==1&&v[4]==1&&v[7]==1) { // line y
        moooves=moooves+"BOYoyb"; return;
    } else if (v[3]==1&&v[4]==1&&v[7]==1) {
        moooves=moooves+"yBOYoyb"; return;
    } else if (v[5]==1&&v[4]==1&&v[7]==1) {
        moooves=moooves+"yyBOYoyb"; return;
    } else if (v[1]==1&&v[4]==1&&v[5]==1) {
        moooves=moooves+"YBOYoyb"; return;
    } else if (v[3]==1&&v[4]==1&&v[1]==1) {
        moooves=moooves+"BOYoyb"; return;
    } else {
        moooves=moooves+"BOYoyb"; return;
    }
    
    
    
    v.clear();
    cubie = cube.cubes[19];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if ((x==0&&y==1&&cubie.getColor(2)==2)|| (x==0&&y==-1&&cubie.getColor(4)==4)|| (y==0&&x==1&&cubie.getColor(1)==1)|| (y==0&&x==-1&&cubie.getColor(3)==3)) {
        v.push_back(19);
    }
    cubie = cube.cubes[21];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if ((x==0&&y==1&&cubie.getColor(2)==2)|| (x==0&&y==-1&&cubie.getColor(4)==4)|| (y==0&&x==1&&cubie.getColor(1)==1)|| (y==0&&x==-1&&cubie.getColor(3)==3)) {
        v.push_back(21);
    }
    cubie = cube.cubes[23];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if ((x==0&&y==1&&cubie.getColor(2)==2)|| (x==0&&y==-1&&cubie.getColor(4)==4)|| (y==0&&x==1&&cubie.getColor(1)==1)|| (y==0&&x==-1&&cubie.getColor(3)==3)) {
        v.push_back(23);
    }
    cubie = cube.cubes[25];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if ((x==0&&y==1&&cubie.getColor(2)==2)|| (x==0&&y==-1&&cubie.getColor(4)==4)|| (y==0&&x==1&&cubie.getColor(1)==1)|| (y==0&&x==-1&&cubie.getColor(3)==3)) {
        v.push_back(25);
    }
    if (v.size() < 2) {
        moooves=moooves+"Y"; return;
    } else if (v.size() == 2) {
        int first = v[0], second = v[1];
        if (first>second) std::swap(first, second);
        
        if (first == 19&&second==21) {
            moooves=moooves+"GYgYGYYgY";return;
        } else if (first == 19&&second==23) {
            moooves=moooves+"RYrYRYYrY";return;
        } else if (first == 21 && second == 25) {
            moooves=moooves+"OYoYOYYoY";return;
        } else if (first == 23 && second == 25) {
            moooves=moooves+"BYbYBYYbY";return;
        } else {
            moooves=moooves+"BYbYBYYbY";return;
        }
    } else {
        
    }
    
    v.clear();
    cubie = cube.cubes[18];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==-1&&y==-1&&z==1) {
        v.push_back(18);
    }
    cubie = cube.cubes[20];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==1&&y==-1&&z==1) {
        v.push_back(20);
    }
    cubie = cube.cubes[24];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==-1&&y==1&&z==1) {
        v.push_back(24);
    }
    cubie = cube.cubes[26];
    x = cubie.getX(); y = cubie.getY(); z = cubie.getZ();
    if (x==1&&y==1&&z==1) {
        v.push_back(26);
    }

    if (v.size()==0) {
        moooves=moooves+"BygYbyGY";return;
    } else if (v.size()==1) {
        switch (v[0]) {
            case 18: {
                moooves=moooves+"BygYbyGY";return;//  YBygYbyG
                break;
            }
            case 20: {
                moooves=moooves+"OyrYoyRY";return;// YOyrYoyR
                break;
            }
            case 24: {
                moooves=moooves+"RyoYryOY";return;//YRyoYryO
                break;
            }
            case 26: {
                moooves=moooves+"GybYgyBY";return;//YGybYgyB
                break;
            }
            default:
                break;
        }
    } else {

    }
}
    solveFinishFlag = true;
    
    // x = 1 y = 1
//    std::vector<int> v;
    if (!solved) {
    cubie = cube.cubes[18];
    int x = cubie.getX(), y = cubie.getY();
    if (x==1&&y==1&&cubie.getColor(5)!=5) {
        moooves = moooves + "owOW";return;
    } else if (x==1&&y==1&&cubie.getColor(5)==5) {
        solveRotCnt++;
        if (solveRotCnt>=4) {
            solved=true;
            moooves = moooves + "Y";
        }
        moooves = moooves + "Y";return;
    }
    cubie = cube.cubes[20];
    x = cubie.getX(); y = cubie.getY();
    if (x==1&&y==1&&cubie.getColor(5)!=5) {
        moooves = moooves + "owOW";return;
    } else if (x==1&&y==1&&cubie.getColor(5)==5) {
        solveRotCnt++;
        if (solveRotCnt>=4) {
            solved=true;
            moooves = moooves + "Y";
        }
        moooves = moooves + "Y";return;
    }
    cubie = cube.cubes[24];
    x = cubie.getX(); y = cubie.getY();
    if (x==1&&y==1&&cubie.getColor(5)!=5) {
        moooves = moooves + "owOW";return;
    } else if (x==1&&y==1&&cubie.getColor(5)==5) {
        solveRotCnt++;
        if (solveRotCnt>=4) {
            solved=true;
            moooves = moooves + "Y";
        }
        moooves = moooves + "Y";return;
    }
    cubie = cube.cubes[26];
    x = cubie.getX(); y = cubie.getY();
    if (x==1&&y==1&&cubie.getColor(5)!=5) {
        moooves = moooves + "owOW";return;
    } else if (x==1&&y==1&&cubie.getColor(5)==5) {
        solveRotCnt++;
        if (solveRotCnt>=4) {
            solved=true;
            moooves = moooves + "Y";
        }
        moooves = moooves + "Y";return;
    }
        
    }
    
    
    
    solveFinishFlag = false;
//    reset(moves, mooves);
}

void cubeController::solverReset() {
    solved = false;
    solveFinishFlag = false;
    solveRotCnt = 0;
    moooves.clear();
}

void cubeController::reset(cubeModel &cube) {
    cube.reset();
}

void cubeController::check(cubeModel &cube) {
    int count=0;
    for (auto& item : cube.cubes) {
        item.setCoords((int)count%3-1, (int)(count/3)%3-1, (int)(count/9)%3-1);
        count++;
        
        for (int i = 0; i < 4 && item.getColor(0)!=0; i++) {
            item.rotX(1);
        }
        if (item.getColor(0)!=0) {
            item.rotY(1);
        }
        for (int i = 0; i < 4 && item.getColor(0)!=0; i++) {
            item.rotX(1);
        }
        for (int i = 0; i < 4 && item.getColor(1)!=1; i++) {
            item.rotZ(1);
        }
    }
    std::cout << "If the cube is not solved it has been altered!" << std::endl;
}
