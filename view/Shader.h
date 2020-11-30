//
// Created by bigcubecat on 28.11.2020.
//

#ifndef GAMEOFLIFE_SHADER_H
#define GAMEOFLIFE_SHADER_H


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

class Shader {
public:
    GLuint Program;

    // Constructor generates the shader on the fly
    Shader(const GLchar *vertexPath, const GLchar *fragmentPath);

    // Uses the current shader
    void Use();
};

#endif //GAMEOFLIFE_SHADER_H
