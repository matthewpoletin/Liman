#include "Application.h"

#include "../Utilities/Logger/Log.h"
#include "../Utilities/Memory/Memory.h"

#include "../FileSystem/Loaders/XmlResourceLoader.h"

namespace liman {

	Application* g_pApp = nullptr;

	Application::Application()
	{
		m_pSettings = NULL;
		m_pGraphicsSystem = NULL;
		m_pTimer = NULL;
		m_pKeyboard = NULL;
		m_pMouse = NULL;
		m_pResCache = NULL;
	}

	bool Application::Init()
	{
		m_pGraphicsSystem = new GraphicsSystem;
		if ((NULL == m_pGraphicsSystem) || (!m_pGraphicsSystem->Init()))
		{
			LOG("Graphics", "Initialization failed");
			return false;
		}

		m_pTimer = new Timer;
		if (NULL == m_pTimer)
		{
			LOG("Application Timer", "Initialization failed");
			return false;
		}

		m_pKeyboard = new KeyboardInput;
		if ((NULL == m_pKeyboard) || (!m_pKeyboard->Init()))
		{
			LOG("Keyboard input", "Initialization failed");
			return false;
		}

		m_pMouse = new MouseInput;
		if ((NULL == m_pMouse) || (!m_pMouse->Init()))
		{
			LOG("Mouse input", "Initialization failed");
			return false;
		}

		return true;
	}

	bool Application::InitResCache()
	{
		m_pResCache = new ResCache(50);
		if ((NULL == m_pResCache) || (!m_pResCache->Init()))
		{
			LOG("Resource Cache", "Initialization failed");
			return false;
		}
		m_pResCache->RegisterLoader(CreateXmlResourceLoader());

		return true;
	}

	bool Application::InitSettings(std::string xmlFileName)
	{

		m_pSettings = new GameSettings;
		if (NULL == m_pSettings)
		{
			LOG("Settings", "Initialization failed");
			return false;
		}
		m_pSettings->Init(xmlFileName);

		return true;
	}

	Application::~Application()
	{
 		SAFE_DELETE(m_pResCache);
		SAFE_DELETE(m_pSettings);
		SAFE_DELETE(m_pGraphicsSystem);
		SAFE_DELETE(m_pKeyboard);
		SAFE_DELETE(m_pTimer);
	}

}