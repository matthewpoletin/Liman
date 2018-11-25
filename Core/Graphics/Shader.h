/**
 * @brief Work with shade files
 * @file Shader.h
 * @author matthewpoletin
 */

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>

#include "Transform.h"
#include "Camera.h"

class Shader {
public:
	/**
	 * Shader constructor
	 * @param fileName Shader file names
	 */
	explicit Shader(const std::string &fileName);

	/**
	 * Bind shader
	 */
	void Bind();

	/**
	 * Update shader
	 * @param transform Transform
	 * @param camera Camera
	 */
	void Update(const Transform &transform, const Camera &camera);

	virtual ~Shader();

protected:
private:
	// Number of shaders
	static const unsigned int NUM_SHADERS = 2;

	/**
	 * Copy constructor
	 * @param other Other shader
	 */
	Shader(const Shader &other);

	enum {
		TRANSFORM_U,
		NUM_UNIFORMS
	};

	/**
	 * Check shader error
	 * @param shader Shader
	 * @param flag Flag
	 * @param isProgram Is program
	 * @param errorMessage Error message
	 */
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);

	/**
	 * Load shader
	 * @param fileName File name
	 * @return Shader
	 */
	static std::string LoadShader(const std::string &fileName);

	/**
	 * Create shader
	 * @param text Shader
	 * @param shaderType Shader type
	 * @return Created shader
	 */
	static GLuint CreateShader(const std::string &text, GLenum shaderType);

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

