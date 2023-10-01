#pragma once

#include <GL/glew.h>


class VertexArray{

public:
    void Init();
    void Bind();
    GLuint GetID();

private:
    GLuint m_id;
};