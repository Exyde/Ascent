#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shaders/shader.hpp"
#include "core/core.hpp"

int main(int argc, char** argv)
{
    //Setup
    Core* core = new Core(600, 400);
    bool succes = core->InitContext();

    if (!succes){
        printf("Failed context initilisation. Quitting...");
        return -1;
    }

    //Work

    //Create and Init a VAO (Vertex Array Object) - Seems it need to exists somewhere in memory ? Yep, doesnt work properly without it at runtime.
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    //Vertices representation
    static const GLfloat g_vertex_buffer_data[] = {
        -2, 0, 0,
        0, 1, 0,
        0, -1, 0,

        0, 0.33, 0,
        2, 0, 0,
        0, -0.33, 0,

        //colors
        1, 0, 0,
        0, 1, 0,
        0, 0, 1,
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    };  

    //Buffer : Linear array of memory, managed by openGL. It can only access some parts of the memory. Kind of GPU Array 
    //We create buffer to store data gpu side. Then we need to bind thoses buffers to context to tell OpenGL What's inside and how to process it.

    //Vertex Buffer
    GLuint vertexBuffer; //Identifier / ID
    glGenBuffers(1, &vertexBuffer); //Creating the actual buffer and put the resulting identifer in vertexbuffer.
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW); //Give the vertices to open GL

    
    const char* VERTEX_SHADER_FILE = "../src/shaders/VertexShader.vertexshader";
    const char* FRAGMENT_SHADER_FILE = "../src/shaders/FragmentShader.fragmentshader";
    //Shaders - Located in "common/shader.hpp"
    GLuint programID = LoadShaders(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE);

    glfwSetInputMode(core->window, GLFW_STICKY_KEYS, GL_TRUE);
    
    do{
        //Clear the screen.
        glClearColor(0.2f, 0.0f, 0.2f, 1.0f);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Set shaders pipe
        glUseProgram(programID);

        //Bind the VBO
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        
        //Draw... !
        glEnableVertexAttribArray(0); //Enable vertex attribute 0 for our shader
        glEnableVertexAttribArray(1);
        //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        //So better, how to interpret datas in the buffer - Always refer to the buffer bound in GL_ARRAY_BUFFER, so here... vertex buffer
        glVertexAttribPointer(
            0,              //Attribute location ?
            3,              //size of the data
            GL_FLOAT,       //type of the data
            GL_FALSE,       //normalized ?
            0,              //Space between data, here 0
            0               //array buffer offset from 0
        );

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)72);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);


        //Buffer Swap
        glfwSwapBuffers(core->window);

        //Polling Events
        glfwPollEvents();

    } while (glfwGetKey(core->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(core->window) == 0);

    return 0;
}
