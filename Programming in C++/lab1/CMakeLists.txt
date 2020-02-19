cmake_minimum_required(VERSION 3.15)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp task_4.cpp task_4.h circle.cpp circle.h task_7.cpp task_7.h Matrix.cpp Matrix.h)

add_executable(test2 ${SOURCE_FILES})