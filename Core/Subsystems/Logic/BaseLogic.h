#pragma once
// BaseLogic.h - deals with in game mechanisms and subsystems

#include "ILogic.h"
#include "../GameState.h"
#include "../../Levels/LevelManager.h"
#include "../../Actors/ActorFactory.h"
#include "../../Collisions/CollisionManager.h"
#include "../../Physics/PhysicsManager.h"
#include "../../Input/InputManager.h"
#include "../../Utilities/Timer/Timer.h"

namespace liman {

	class LevelManager;
	class ActorFactory;

	class BaseLogic : public ILogic
	{
	public:
		BaseLogic();
		~BaseLogic();

		bool Init(void);

		void ChangeGameState(GameState state);

		virtual bool VLoadGame(const char* levelName);

		LevelManager* GetLevelManager();
		ActorFactory* GetActorFactory();
		CollisionManager* GetCollisionManager();
		PhysicsManager* GetPhysicsManager();
		InputManager* GetInputManager() { return m_pInputManager; }
		Timer* GetTimer() { return m_pTimer; }

	private:
		LevelManager* m_pLevelManager;
		ActorFactory* m_pActorFactory;
		CollisionManager* m_pCollisionManager;
		PhysicsManager* m_pPhysicsManager;
		InputManager* m_pInputManager;

		// TIP: ingame time (may be paused during the application is running)
		Timer* m_pTimer;

	protected:
		GameState m_gameState;	// game state: loading, running, etc.

	};

}