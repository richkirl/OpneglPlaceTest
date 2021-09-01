#ifndef EBO_HPP
#define EBO_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class EBO{
public:
    GLuint ID;
    EBO(GLuint* indicies, GLsizeiptr size);
  //  void EBO_dyn(GLuint* indices, GLsizeiptr size);
    void Bind();
    void Unbind();
    void Delete();

};
#endif
