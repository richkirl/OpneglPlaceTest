#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "EBO.hpp"

    EBO::EBO(GLuint* indicies, GLsizeiptr size) {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
    }

//void EBO::EBO_dyn(GLuint* indices, GLsizeiptr size)
//{
//  glGenBuffers(1,&ID);
//  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ID);
//  glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,indices,GL_DYNAMIC_DRAW);
//}
    void EBO::Bind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    }

    void EBO::Unbind() {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    void EBO::Delete() {
        glDeleteBuffers(1, &ID);
    }
