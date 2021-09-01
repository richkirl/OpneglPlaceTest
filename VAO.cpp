#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VBO.hpp"
#include "VAO.hpp"

    VAO::VAO() {
        glGenVertexArrays(1, &ID);
    }

    void VAO::LinkAttrib(VBO& vbo, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
    {
        vbo.Bind();
        glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
        glEnableVertexAttribArray(layout);
        vbo.Unbind();
    }
    void VAO::Bind() {
        glBindVertexArray(ID);
    }
    void VAO::Unbind() {
        glBindVertexArray(0);
    }
    void VAO::Delete() {
        glDeleteVertexArrays(1, &ID);
    }
