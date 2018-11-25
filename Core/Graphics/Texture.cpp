#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <stb_image.h>

namespace liman {

	Texture::Texture(const std::string &fileName) {
		int width, height, numComponents;
		stbi_uc* imageData = stbi_load((fileName).c_str(), &width, &height, &numComponents, 4);

		SetTexture(width, height, numComponents, imageData);
	}

	Texture::Texture(unsigned char* buffer, unsigned int size) {
		int width, height, numComponents;

		stbi_uc* imageData = stbi_load_from_memory(buffer, size, &width, &height, &numComponents, 4);

		SetTexture(width, height, numComponents, imageData);
	}

	void Texture::SetTexture(int width, int height, int numComponents, stbi_uc* imageData) {
		m_width = static_cast<unsigned int>(width);
		m_height = static_cast<unsigned int>(height);

		if (imageData == nullptr)
			std::cerr << "Error: Texture loading failed!" << std::endl;

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		bool bPixels = true;
		if (bPixels) {
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		} else {
			// Linearly extrapolate textures
			//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

		stbi_image_free(imageData);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &m_texture);
	}

	void Texture::Bind() {
		glBindTexture(GL_TEXTURE_2D, m_texture);
	}

}
