#include "Texture.hpp"
#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <iostream>
Texture::Texture(unsigned int id): id (id)
{

}

Texture::~Texture()
{
	glDeleteTextures(1,&id);
}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, id);
}

int load_image(std::string filename)
{
	
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
    //
    unsigned int texture;
    // texture 1
    // ---------
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load image, create texture and generate mipmaps
    glBindTexture(GL_TEXTURE_2D, 0);

     // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    
    
    
    //data
    stbi_image_free(data);
	return texture;
}

Texture* load_texture(std::string filename)
{
	
	GLuint texture = load_image(filename);
	if (texture == 0) {
		std::cerr << "Could not open PNG file"<< filename << std::endl;
		return nullptr;
	}
    
	return new Texture(texture);
}
