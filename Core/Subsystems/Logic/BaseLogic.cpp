#include "BaseLogic.h"

#include "../../Utilities/Logger/Log.h"

namespace liman {

	BaseLogic::BaseLogic()
	{
		m_pLevelManager = NULL;
		m_pActorFactory = NULL;
		m_pCollisionManager = NULL;
		m_pPhysicsManager = NULL;
		m_pInputManager = NULL;
		m_pTimer = NULL;
	}

	BaseLogic::~BaseLogic()
	{
		delete  m_pLevelManager;
		delete m_pActorFactory;

		delete m_pTimer;
	}

	bool BaseLogic::Init()
	{
		m_pLevelManager = new LevelManager();
		m_pActorFactory = new ActorFactory();
		m_pCollisionManager = new CollisionManager();
		m_pPhysicsManager = new PhysicsManager();
		m_pInputManager = new InputManager();

		m_pTimer = new Timer;
		if (NULL == m_pTimer)
		{
			LOG("Logic Timer", "Initialization failed");
			return false;
		}

		return true;
	}

	void BaseLogic::ChangeGameState(GameState state)
	{
		m_gameState = state;
	}

	bool BaseLogic::VLoadGame(const char* levelName)
	{
		if (!this->GetLevelManager()->LoadLevel(levelName))
		{
			LOG("Level manager", "Loading level failed");
			return false;
		}
		return true;
	}

	LevelManager* BaseLogic::GetLevelManager()
	{
		return m_pLevelManager;
	}

	ActorFactory* BaseLogic::GetActorFactory()
	{
		return m_pActorFactory;
	}

	CollisionManager* BaseLogic::GetCollisionManager()
	{
		return m_pCollisionManager;
	}

	PhysicsManager* BaseLogic::GetPhysicsManager()
	{
		return m_pPhysicsManager;
	}

}