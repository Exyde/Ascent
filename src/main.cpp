#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstring> //for memcpy

//Imgui BEFORE 
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#include "shaders/shader.hpp"
#include "core/core.hpp"

//Wrapper
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"


//Shaders
//const char* VERTEX_SHADER_FILE = "../src/shaders/VertexShader.glsl";
const char* VERTEX_SHADER_FILE = "../src/shaders/ManualPerspective.glsl";
const char* FRAGMENT_SHADER_FILE = "../src/shaders/FragmentShader.glsl";

void ComputePositionsOffsets(float &xOffset, float &yOffset);
void AdjustVertexData(float xOffset, float yOffset, GLuint &vertexBuffer);

void SetUniforms(GLuint &programID);

//Datas. Here vertices containing positions and colors.
const float vertexDatas[] = {
	 0.25f,  0.25f, -1.25f, 1.0f,
	 0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,

	 0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,

	 0.25f,  0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,
	 0.25f, -0.25f, -2.75f, 1.0f,

	 0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,

	-0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,

	-0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,

	 0.25f,  0.25f, -1.25f, 1.0f,
	 0.25f, -0.25f, -2.75f, 1.0f,
	 0.25f, -0.25f, -1.25f, 1.0f,

	 0.25f,  0.25f, -1.25f, 1.0f,
	 0.25f,  0.25f, -2.75f, 1.0f,
	 0.25f, -0.25f, -2.75f, 1.0f,

	 0.25f,  0.25f, -2.75f, 1.0f,
	 0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,

	 0.25f,  0.25f, -2.75f, 1.0f,
	-0.25f,  0.25f, -1.25f, 1.0f,
	-0.25f,  0.25f, -2.75f, 1.0f,

	 0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,
	 0.25f, -0.25f, -1.25f, 1.0f,

	 0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -2.75f, 1.0f,
	-0.25f, -0.25f, -1.25f, 1.0f,




	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,
	0.8f, 0.8f, 0.8f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,
	0.5f, 0.5f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,
	0.0f, 1.0f, 1.0f, 1.0f,

};

int main(int argc, char** argv)
{
    //Setup
    Core* core = new Core(600, 400);

    GLFWwindow* window = core->InitContext();

    if (window == nullptr){
        printf("Failed context initilisation. Quitting...");
        return -1;
    }

    //VAO 
    VertexArray vertexArray;
    vertexArray.Init();
    vertexArray.Bind();

    //Culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK); //Back face - Can be front or both
    glFrontFace(GL_CW); //Clock-wise. Can be CCW.

    //Setup basic Shaders
    Shader shader;
    GLuint programID = shader.LoadShaders(VERTEX_SHADER_FILE, FRAGMENT_SHADER_FILE);

    //Vertex Buffer
    VertexBuffer vertexBuffer = VertexBuffer(GLuint(sizeof(vertexDatas)), vertexDatas); //Init, Bind and Set Datas.

    glfwSetInputMode(core->window, GLFW_STICKY_KEYS, GL_TRUE);

    GLint timeUniformID = glGetUniformLocation(programID, "time"); //All shader shoulds have acces to time imo.
    SetUniforms(programID);

    do{
        //Clear the screen.
        glClearColor(0.2f, 0.0f, 0.2f, 1.0f);
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Set shaders pipe
        glUseProgram(programID);

        //Set Uniforms
        glUniform1f(timeUniformID, glfwGetTime());

        //Bind the VBO
        vertexBuffer.Bind();
        size_t colorData = sizeof(vertexDatas) / 2; //Half the size of the array, easier for VertexAttribPointer last param !
        
        //Draw... !
        glEnableVertexAttribArray(0); //Enable vertex attribute 0 for our shader
        glEnableVertexAttribArray(1);
        //glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        //So better, how to interpret datas in the buffer - Always refer to the buffer bound in GL_ARRAY_BUFFER, so here... vertex buffer
        glVertexAttribPointer(
            0,              //Attribute location ?
            4,              //size of the data
            GL_FLOAT,       //type of the data
            GL_FALSE,       //normalized ?
            0,              //Space between data, here 0
            0               //array buffer offset from 0
        );

        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)colorData);

        glDrawArrays(GL_TRIANGLES, 0,36);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        //Buffer Swap
        glfwSwapBuffers(core->window);

        //Polling Events
        glfwPollEvents();

    } while (glfwGetKey(core->window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

    return 0;
}

void SetUniforms(GLuint &programID){
    //Setup Uniforms
    GLint offsetUniformID = glGetUniformLocation(programID, "offset"); //Way to query an uniform ID
    GLint loopDurationUniformID = glGetUniformLocation(programID, "loopDuration");
    GLint fragLoopDurationUniformID = glGetUniformLocation(programID, "fragLoopDuration");

    GLint zFarUniformID = glGetUniformLocation(programID, "zFar");
    GLint zNearUniformIDzFarUniformID = glGetUniformLocation(programID, "zNear");
    GLint frustrumScaleUniformIDzFarUniformID = glGetUniformLocation(programID, "frustrumScale");

    glUseProgram(programID);
    glUniform1f(loopDurationUniformID, 3.0f);
    glUniform1f(fragLoopDurationUniformID, 3.0f); 

//______________
    //SetPerspective Matrix
    //Manual Way.
    /*
    glUniform1f(zNearUniformIDzFarUniformID, 1.0f); 
    glUniform1f(zFarUniformID, 3.0f); //No error if you don't use the program before...
    glUniform1f(frustrumScaleUniformIDzFarUniformID, 1.0f); 
    */

    //Matrices Way
    GLint perspectiveMatrixUnifromID = glGetUniformLocation(programID, "perspectiveMatrix");
    float frustrumScale = 0.5f; float zNear = 1.0f; float zFar = 3.0f;

    float matrix[16];
    memset(matrix, 0, sizeof(float)* 16);

    matrix[0] = frustrumScale; //First indice
    matrix[5] = frustrumScale * 1.2f; //Second column, second row.
    matrix[10] = (zFar + zNear) / (zNear - zFar); //Third colum, third row.
    matrix[14] = (2 * zFar * zNear) / (zNear - zFar);//Last column,  third row
    matrix[11] = -1.0f; //Third column, last row !

    glUniformMatrix4fv(perspectiveMatrixUnifromID, 1, GL_FALSE, matrix); //True if row-major, here we are column major.
    glUniform2f(offsetUniformID, 0.5f,  0.5f); //Uniform ID, value1, value2 | Must be after the program is set in.
    glUseProgram(0);
}