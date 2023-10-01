#include "VertexArray.hpp"


void VertexArray::Init(){
    glGenVertexArrays(1, &m_id);
    glBindVertexArray(m_id);
}

void VertexArray::Bind(){
    glBindVertexArray(m_id);
}


GLuint VertexArray::GetID(){
    return m_id;
}
