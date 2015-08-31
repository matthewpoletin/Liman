#pragma once
// Application.h - class that works with displays, keyboards, mouses and so on.

#include <string>

#include "Settings.h"
#include "../Graphics/GraphicsSystem.h"
#include "../Utilities/Timer/Timer.h"
#include "../Input/KeyboardInput.h"
#include "../Input/MouseInput.h"
#include "../FileSystem/ResCache.h"
#include "BaseGameLogic.h"

namespace liman {

	class ResCache;
	class BaseGameLogic;

	class Application
	{
	protected:
		bool m_bIsRunning;
		bool m_bIsEditorRunning;				// true if the game editor is running

	public:
		Application();
		~Application();

		bool Init();
		bool InitResCache();
		bool InitSettings(std::string xmlFileName);

		bool IsRunning() { return m_bIsRunning; }

		BaseGameLogic* GetGameLogic() { return m_pGame; }
		GraphicsSystem* GetGraphicsSystem() { return m_pGraphicsSystem; }
		ResCache* GetResCahe() { return m_pResCache; }
		GameSettings* GetSettings() { return m_pSettings; }

		void SetKeyboard(KeyboardInput* pKeyboard) { m_pKeyboard = pKeyboard; }
		KeyboardInput* GetKeyboard() { return m_pKeyboard; }

		inline MouseInput* GetMouse() { return m_pMouse; }

		void SetTimer(Timer* pTimer) { m_pTimer = pTimer; }
		Timer* GetTimer() { return m_pTimer; }
	private:
		BaseGameLogic* m_pGame;
		GraphicsSystem* m_pGraphicsSystem;
		ResCache* m_pResCache;
		GameSettings* m_pSettings;
		KeyboardInput* m_pKeyboard;
		MouseInput* m_pMouse;
		Timer* m_pTimer;	// engine time
	};

	extern Application* g_pApp;
}