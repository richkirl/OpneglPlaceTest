#pragma once
#ifndef TEXT_HPP
#define TEXT_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include "Buffers.hpp"
#include "Shader.hpp"
#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H
class Text
{
public:
    struct Character {
        unsigned int TextureID; // ID handle of the glyph texture
        glm::ivec2   Size;      // Size of glyph
        glm::ivec2   Bearing;   // Offset from baseline to left/top of glyph
        unsigned int Advance;   // Horizontal offset to advance to next glyph
    };

    std::map<GLchar, Character> Characters;

    VAO vao;
    VBO vbo;

    Shader *textShader;

    FT_Library ft;

    std::string font_path;

    FT_Face face;


    void init();
    void RenderText(std::string text, float x, float y, float scale, glm::vec3 color);
    void clean();
	Text();

	~Text();
};


#endif // !TEXT_HPP



