#include "Application.h"

namespace liman {

	Application* g_pApp = nullptr;

	Application::Application() {
		m_pSettings = nullptr;
		m_pGraphicsSystem = nullptr;
		m_pTimer = nullptr;
		m_pKeyboard = nullptr;
		m_pMouse = nullptr;
		m_pResCache = nullptr;
	}

	bool Application::VInit() {
		Log::Init("");
		LOG("Info", "Initializing subsystems");

		if (!this->InitResCache()) {
			LOG("Resource Cache", "Initialization failed");
			return false;
		}

#ifdef DEBUG
		std::string path = "../../../Assets/Paths.xml";
#else
		// TODO: Change to relative paths
		std::string path = "/Users/matthewpoletin/Documents/Projects/Personal/Liman/Resources/Paths.xml";
//		std::string path = "Resources/Paths.xml";
#endif
		if (!this->GetResCahe()->LoadPaths(path)) {
			LOG("Resource Cache", "Loading paths failed");
			return false;
		}

		if (!this->InitSettings("Settings.xml")) {
			LOG("Application", "Settings loading failed");
			return false;
		}

		m_pGraphicsSystem = new GraphicsSystem;
		if ((nullptr == m_pGraphicsSystem) || (!m_pGraphicsSystem->Init())) {
			LOG("Graphics", "Initialization failed");
			return false;
		}

		m_pTimer = new Timer;
		if (nullptr == m_pTimer) {
			LOG("Application Timer", "Initialization failed");
			return false;
		}

		m_pKeyboard = new KeyboardInput;
		if ((nullptr == m_pKeyboard) || (!m_pKeyboard->Init())) {
			LOG("Keyboard input", "Initialization failed");
			return false;
		}

		m_pMouse = new MouseInput;
		if ((nullptr == m_pMouse) || (!m_pMouse->Init())) {
			LOG("Mouse input", "Initialization failed");
			return false;
		}

		return true;
	}

	bool Application::InitResCache() {
		m_pResCache = new ResCache(50);
		if ((nullptr == m_pResCache) || (!m_pResCache->Init())) {
			LOG("Resource Cache", "Initialization failed");
			return false;
		}
		m_pResCache->RegisterLoader(CreateXmlResourceLoader());

		return true;
	}

	bool Application::InitSettings(std::string xmlFileName) {
		m_pSettings = new GameSettings;
		if (nullptr == m_pSettings) {
			LOG("Settings", "Initialization failed");
			return false;
		}
		m_pSettings->Init(xmlFileName);

		return true;
	}

	Application::~Application() {
		SAFE_DELETE(m_pResCache);
		SAFE_DELETE(m_pSettings);
		SAFE_DELETE(m_pGraphicsSystem);
		SAFE_DELETE(m_pKeyboard);
		SAFE_DELETE(m_pTimer);
	}

}