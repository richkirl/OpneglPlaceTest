#include <GL/glew.h>
#include "VBO.hpp"
#include <GLFW/glfw3.h>
#include <string>

    VBO::VBO()
    {
    }

    VBO::VBO(GLfloat* vertices, GLsizeiptr size)
    {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    }

    VBO::VBO(GLfloat* vertices, GLsizeiptr size,std::string r)
    {
	  if(&r[0]=="d"&& &r[2]=="n"&& &r[4]=="m"&& &r[6]=="c"){
	  
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
	  }
    }

void VBO::VBO_Dyn(GLfloat *vertices, GLsizeiptr size)
{
  glGenBuffers(1,&ID);
  glBindBuffer(GL_ARRAY_BUFFER,ID);
  glBufferData(GL_ARRAY_BUFFER,size,vertices,GL_DYNAMIC_DRAW);
}
    void VBO::Bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }

    void VBO::Unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    void VBO::Delete()
    {
        glDeleteBuffers(1, &ID);
    }
