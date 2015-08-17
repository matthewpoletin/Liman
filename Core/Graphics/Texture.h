#pragma once

#include <string>
#include <GL/glew.h>
#include <stb/stb_image.h>

class Texture
{
public:
	Texture(const std::string& fileName);
	Texture(stbi_uc* buffer, unsigned int size);

	void SetTexture(int width, int height, int numComponents, stbi_uc* imageData);

	void Bind();

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }

	virtual ~Texture();

private:
	Texture(const Texture& other) {}
	void operator=(const Texture&other) {}

	unsigned int m_width;
	unsigned int m_height;

	GLuint m_texture;
};

