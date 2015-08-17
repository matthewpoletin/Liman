#include "BaseGameLogic.h"

#include "../Utilities/Logger/Log.h"

namespace liman {

	BaseGameLogic* g_pBGL = nullptr;

	BaseGameLogic::BaseGameLogic()
	{
		m_pLevelManager = NULL;
		m_pActorFactory = NULL;
		m_pCollisionManager = NULL;
		m_pPhysicsManager = NULL;
		m_pInputManager = NULL;
		m_pTimer = NULL;
	}

	BaseGameLogic::~BaseGameLogic()
	{
		delete  m_pLevelManager;
		delete m_pActorFactory;

		delete m_pTimer;
	}

	bool BaseGameLogic::Init()
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

	void BaseGameLogic::ChangeGameState(GameState state)
	{
		m_gameState = state;
	}

	bool BaseGameLogic::VLoadGame(const char* levelName)
	{
		if (!this->GetLevelManager()->LoadLevel(levelName))
		{
			LOG("Level manager", "Loading level failed");
			return false;
		}
		return true;
	}

	LevelManager* BaseGameLogic::GetLevelManager()
	{
		return m_pLevelManager;
	}

	ActorFactory* BaseGameLogic::GetActorFactory()
	{
		return m_pActorFactory;
	}

	CollisionManager* BaseGameLogic::GetCollisionManager()
	{
		return m_pCollisionManager;
	}

	PhysicsManager* BaseGameLogic::GetPhysicsManager()
	{
		return m_pPhysicsManager;
	}

}