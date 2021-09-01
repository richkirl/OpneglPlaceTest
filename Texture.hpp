#pragma once
#ifndef TEXTURE_HPP
#define TEXTURE_HPP
#include <string>
class Texture
{
public:
	unsigned int id;
	int w, h;
	Texture(unsigned int id);
	~Texture();
	void bind();
};
extern Texture* load_texture(std::string filename);
#endif // !TEXTURE_HPP



