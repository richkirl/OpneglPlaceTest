#ifndef VBO_HPP
#define VBO_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
class VBO{
public:
    GLuint ID;
    VBO();
    VBO(GLfloat* vertices, GLsizeiptr size);
    VBO(GLfloat* vertices, GLsizeiptr size,std::string r);
    void VBO_Dyn(GLfloat* vertices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();
};
#endif
