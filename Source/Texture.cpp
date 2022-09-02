#include "Texture.h"
#include <stb/stb_image.h>
#include <iostream>

Texture::Texture(const std::string& path)
	: filepath(path), local_buffer(nullptr),
	width(0), height(0), bpp(0)
{
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	stbi_set_flip_vertically_on_load(true);
	local_buffer = stbi_load(path.c_str(), &width, &height, &bpp, 4);

	//These parameters are required! If you do not set them, tex will be black
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, local_buffer);

	glBindTexture(GL_TEXTURE_2D, 0);

	if (local_buffer)
		stbi_image_free(local_buffer);
}

Texture::~Texture()
{
	glDeleteTextures(1, &id);
}

void Texture::Bind(unsigned int slot) const
{
	if (slot > 32 || slot < 0) {
		//Invalid slot!
		std::cout << "Texture assigned to invalid slot!" << std::endl;
		return;
	}

	//After this call next bound texture will be assign to specified slot
	glActiveTexture(GL_TEXTURE0 + slot);

	//Bind tex and assign to slot 0
	glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::Unbind() const
{
}
