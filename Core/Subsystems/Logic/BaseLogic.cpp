#include "BaseLogic.h"

#include "../../Utilities/Logger/Log.h"

namespace liman {

	BaseLogic::BaseLogic() {
		m_pLevelManager = nullptr;
		m_pActorFactory = nullptr;
		m_pInputManager = nullptr;
		m_pTimer = nullptr;
	}

	BaseLogic::~BaseLogic() {
		delete m_pLevelManager;
		delete m_pActorFactory;

		delete m_pTimer;
	}

	bool BaseLogic::VInit() {
		m_pLevelManager = new LevelManager();
		m_pActorFactory = new ActorFactory();
		m_pInputManager = new InputManager();

		m_pTimer = new Timer;
		if (nullptr == m_pTimer) {
			LOG("Logic Timer", "Initialization failed");
			return false;
		}

		return true;
	}

	bool BaseLogic::VLoadGame(const char* levelName) {
		if (!this->GetLevelManager()->LoadLevel(levelName)) {
			LOG("Level manager", "Loading level failed");
			return false;
		}
		return true;
	}

	LevelManager* BaseLogic::GetLevelManager() {
		return m_pLevelManager;
	}

	ActorFactory* BaseLogic::GetActorFactory() {
		return m_pActorFactory;
	}

}