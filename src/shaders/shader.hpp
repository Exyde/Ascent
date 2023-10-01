#ifndef SHADER_HPP
#define SHADER_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Shader{
    public:
    GLuint ReadCompileAndCheckShader(const char* path, const GLuint ID);
    GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);
};
#endif