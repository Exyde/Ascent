#include "core.hpp"
#include <fstream>

Core::Core(const uint width, const uint height){
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
}

bool Core::Init_GLFW(){
    if (!glfwInit()){
        fprintf( stderr, "Failed to initalize GLFW\n" );
        return false;
    }
    return true;
}

bool Core::Init_GLEW(){
    if (glewInit() != GLEW_OK){
        fprintf(stderr, "Failed to initialize GLEW\n");
        return false;
    }
    return true;
}

void Core::SetWindowHints(){
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x Anti-Aliasing.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL Version, 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //Mac Os Happy.
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old open GL... so ?
}


bool Core::SetupWindow(){
   
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Ascent Engine", NULL, NULL);

    if (window == NULL){
        fprintf( stderr, "Failed to open GLFW Window. If you have an Intel GPU, they are not 3.3 compatible. Try with the 2.1 version.\n" );
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    return true;
}

bool Core::InitContext(){

    glewExperimental = true;

    if (!Init_GLFW()) return false;

    SetWindowHints();
    SetupWindow();

    if (!Init_GLEW()) return false;

    return true;
}