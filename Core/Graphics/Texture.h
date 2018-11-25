/**
 * @file Texture.h
 * @author matthewpoletin
 */

#pragma once

#include <string>
#include <GL/glew.h>
#include <stb_image.h>

namespace liman {

	class Texture {
	public:
		/**
		 * Create texture
		 * @param fileName File name of texture
		 */
		explicit Texture(const std::string &fileName);

		Texture(stbi_uc* buffer, unsigned int size);

		void SetTexture(int width, int height, int numComponents, stbi_uc* imageData);

		void Bind();

		/**
		 * Get width of texture
		 * @return Width of texture
		 */
		int GetWidth() { return m_width; }

		/**
		 * Get height of texture
		 * @return Height of texture
		 */
		int GetHeight() { return m_height; }

		virtual ~Texture();

	private:
		Texture(const Texture &other) {}

		void operator=(const Texture &other) {}

		unsigned int m_width;
		unsigned int m_height;

		GLuint m_texture;

	};

}
