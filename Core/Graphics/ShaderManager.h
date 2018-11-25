/**
 * @file ShaderManager.h
 * @author matthewpoletin
 */

#pragma once

#include <map>
#include <list>
#include <string>

#include "Shader.h"
#include "../Utilities/Logger/Log.h"
#include "../Application.h"

namespace liman {

	typedef std::list<std::string> ShaderList;
	typedef std::map<std::string, Shader*> ShaderMap;

	class ShaderManager {
	public:
		ShaderManager() = default;

		~ShaderManager();

		bool CreateShader(std::string shaderStr);

		bool AddShader(std::string shaderName, Shader* pShader);

		Shader* GetShader(std::string shaderStr);

		bool DeleteShader(std::string shaderName);

		ShaderList GetShaderList() { return m_shaderList; }

	private:
		ShaderList m_shaderList;
		ShaderMap m_shaders;

	};

}