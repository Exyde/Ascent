#ifndef CORE_HPP
#define CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Core{
    
public:
//Globals
    Core(const uint width, const uint height);
    GLFWwindow* window;
    int WINDOW_HEIGHT;
    int WINDOW_WIDTH;
    //Methods
    bool InitContext();

private:
    bool SetupWindow();
    void SetWindowHints();
    bool Init_GLEW();
    bool Init_GLFW();
};

#endif
