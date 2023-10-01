#pragma once

#include "GL/glew.h"

class VertexBuffer{

public:
    VertexBuffer(GLuint size, const float data[]);
    void Init();
    void Bind() const;
    GLuint GetID() const;
    GLuint GetSize() const;
    void SetData(const float data[]) const;
    void UpdateData(const float data[]) const;
private:
    GLuint m_id;
    GLuint m_size;
};
