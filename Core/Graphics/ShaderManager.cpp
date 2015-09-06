#include "ShaderManager.h"

namespace liman {

	ShaderManager::ShaderManager()
	{

	}

	ShaderManager::~ShaderManager()
	{
		auto it = m_shaders.begin();
		while (it != m_shaders.end())
			m_shaders.erase(it);
	}

	bool ShaderManager::CreateShader(std::string shaderStr)
	{
		auto findIt = m_shaders.find(shaderStr);
		if (findIt == m_shaders.end())
		{
			LOG("ShaderManager", "Creating shader " + shaderStr);
			Shader* pShader = new Shader(liman::g_pApp->GetResCahe()->GetPath("Shaders") + shaderStr);
			m_shaders.insert(std::make_pair(shaderStr, pShader));
			m_shaderList.push_back(shaderStr);
			return true;
		}
		else
		{
			LOG("ShaderManager", "Specified shader " + shaderStr + " already exists");
			return false;
		}
	}

	bool ShaderManager::AddShader(std::string shaderName, Shader* pShader)
	{
		// ToDo: Write map insertion

		return true;
	}

	Shader* ShaderManager::GetShader(std::string shaderStr)
	{
		auto findIt = m_shaders.find(shaderStr);
		if (findIt == m_shaders.end())
		{
			LOG("ShaderManager", "Specified shader " + shaderStr + " was not found");
			return nullptr;
		}
		else
		{
			return findIt->second;
		}
	}

	bool ShaderManager::DeleteShader(std::string shaderName)
	{
		auto findIt = m_shaders.find(shaderName);
		if (findIt == m_shaders.end())
		{
			LOG("ShaderManager", "Specified shader " + shaderName + " was not found");
			return false;
		}
		else
		{
			m_shaders.erase(shaderName);
			m_shaderList.remove(shaderName);
			return true;
		}
	}

}