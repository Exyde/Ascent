#pragma once

#include <GL/glew.h>


class VertexArray{

public:
    void Init();
    void Bind();
    void Unbind();
    GLuint GetID();

private:
    GLuint m_id;
};