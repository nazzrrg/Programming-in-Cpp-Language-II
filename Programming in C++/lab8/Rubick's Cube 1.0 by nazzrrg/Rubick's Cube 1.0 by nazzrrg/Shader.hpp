//
//  Shader.h
//  Rubick's 0.1
//
//  Created by Егор Назаров on 17.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef Shader_h
#define Shader_h

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>
#include <OpenGL/gl3.h>

#define GL_SILENCE_DEPRECATION

class Shader {
public:
    GLuint Program;
    
    Shader(const std::string& vertexPath, const std::string& fragmentPath) {
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        vShaderFile.exceptions (std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::badbit);
        try
        {
            vShaderFile.open(vertexPath.c_str(), std::ios::in);
            if (!vShaderFile.is_open()) {
                throw std::runtime_error(std::string("Failed to open shader file: ") + std::string(vertexPath));
            }

            fShaderFile.open(fragmentPath.c_str(), std::ios::in);
            if (!fShaderFile.is_open()) {
                throw std::runtime_error(std::string("Failed to open shader file: ") + std::string(fragmentPath));
            }

            std::stringstream vShaderStream, fShaderStream;

            vShaderStream << vShaderFile.rdbuf();
            vShaderStream << "\0";
            fShaderStream << fShaderFile.rdbuf();
            fShaderStream << "\0";

            vShaderFile.close();
            fShaderFile.close();

            vertexCode = vShaderStream.str( );
            fragmentCode = fShaderStream.str( );
        }
        catch ( std::ifstream::failure e )
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }

        const GLchar *vShaderCode = (const GLchar *)vertexCode.c_str();
        const GLchar *fShaderCode = (const GLchar *)fragmentCode.c_str();
        
        // Compile shaders
        GLuint vertex, fragment;
        GLint success;
        GLchar infoLog[512];
        // Vertex Shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, NULL);
        glCompileShader(vertex);
        
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertex, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        
        // Fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, NULL);
        glCompileShader(fragment);
        
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragment, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        
        // Shader Program
        this->Program = glCreateProgram();
        glAttachShader(this->Program, vertex);
        glAttachShader(this->Program, fragment);
        glLinkProgram(this->Program);
        
        glGetProgramiv(this->Program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(this->Program, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        

        glDeleteShader(vertex);
        glDeleteShader(fragment);
        
    }
    // Uses the current shader
    void Use() const {
        glUseProgram(this->Program);
    }
};

#endif /* Shader_h */
