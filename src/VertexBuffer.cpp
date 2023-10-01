#include "VertexBuffer.hpp"
#include <iostream>

VertexBuffer::VertexBuffer(GLuint size, const float data[] = NULL){
    Init();
    Bind();

    m_size = size;

    if (data != NULL){
        SetData(data);
    }
}

void VertexBuffer::Init(){
    glGenBuffers(1, &m_id);
}

void VertexBuffer::Bind() const{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::Unbind() const{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::SetData(const float data[]) const{
    glBufferData(GL_ARRAY_BUFFER, m_size, data, GL_STATIC_DRAW);
}

void VertexBuffer::UpdateData(const float newData[]) const{
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_size, &newData[0]);
}

GLuint VertexBuffer::GetID() const{
    return m_id;
}

GLuint VertexBuffer::GetSize() const{
    return m_size;
}