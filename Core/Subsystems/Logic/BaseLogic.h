/**
 * @brief Deals with in game mechanisms and subsystems
 * @file BaseLogic.h
 * @author matthewpoletin
 */

#pragma once

#include "ILogic.h"
#include "../../Levels/LevelManager.h"
#include "../../Actors/ActorFactory.h"
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

	public:
		virtual bool VInit(void);

	public:
		virtual bool VLoadGame(const char* levelName);

	public:
		LevelManager* GetLevelManager();
		ActorFactory* GetActorFactory();
		InputManager* GetInputManager() { return m_pInputManager; }
		Timer* GetTimer() { return m_pTimer; }

	protected:
		LevelManager* m_pLevelManager;
		ActorFactory* m_pActorFactory;
		InputManager* m_pInputManager;
		// TIP: ingame time (may be paused during the application is running)
		Timer* m_pTimer;

	};

}