#pragma once

#include "Renderer.h"

class Texture {
private:
	unsigned int id;
	std::string filepath;
	unsigned char* local_buffer;
	int width, height, bpp;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;

	inline int GetWidth() const { return width; };
	inline int GetHeight() const { return height; };
};