#include "Game.h"

namespace liman {

	#ifdef WINDOWS
	#include <Windows.h>
	#elif MACOSX
	#include <unistd.h>
	#endif

	Game::Game()
	{
		m_state = Application::State::S_Invalid;
		g_pApp = this;
	}
	
	bool Game::VInit()
	{
		#ifdef NDEBUG
		ShowWindow(GetConsoleWindow(), SW_HIDE);
		#endif
		m_state = Application::State::S_Initializing;

		if (!Application::VInit())
		{
			LOG("Application", "Initialization failed");
			return false;
		}

		m_pLogic = new BaseGameLogic();

		if (!m_pLogic->VInit())
		{
			LOG("Application", "Logic Initialization failed");
			return false;
		}

		//TODO: Move used keys init to settings loading/changing
		for (unsigned int keyCounter = 0; keyCounter < MAX_KEYS; keyCounter++)
		{
			m_pLogic->GetInputManager()->SetKey(keyCounter);
		}
		for (unsigned int buttonCounter = 0; buttonCounter < MAX_BUTTONS; buttonCounter++)
		{
			m_pLogic->GetInputManager()->SetKey(buttonCounter);
		}

		m_pLogic->VLoadGame(liman::g_pApp->GetSettings()->level.c_str());

		m_pLogic->GetLevelManager()->GetActorsInfo();

		this->GetGraphicsSystem()->GetShaderManager()->CreateShader("basicShader");
		
		m_state = Application::State::S_Running;
		return true;
	}

	void Game::VDoLoop()
	{
		this->GetTimer()->StartTimer();

		m_pLogic->GetInputManager()->Update();

		//TempInputReaction();

		m_pLogic->GetCollisionManager()->UpdateCollision();

		m_pLogic->GetPhysicsManager()->UpdateMovables(this->GetSettings()->display.msPerFrame);

		this->GetGraphicsSystem()->Draw();

		this->GetTimer()->StopTimer();
		if (this->GetTimer()->GetDelta() < this->GetSettings()->display.msPerFrame)
		{
			double sleepTimeMS = this->GetSettings()->display.msPerFrame - this->GetTimer()->GetDelta();
#ifdef WINDOWS
			Sleep((DWORD)sleepTimeMS);
#elif MACOSX
			sleep(sleepTimeMS);
#endif
		}
	}
	
	bool Game::VDeInit()
	{
		return true;
	}

}
