/**
 * @brief Work with displays, keyboards, mouses and so on.
 * @file Application.h
 * @author matthewpoletin
 */

#pragma once

#include <string>

#include "Utilities/Logger/Log.h"
#include "Utilities/Memory/Memory.h"
#include "FileSystem/Loaders/XmlResourceLoader.h"

#include "Subsystems/Logic/BaseLogic.h"
#include "Subsystems/Settings.h"
#include "Graphics/GraphicsSystem.h"
#include "Utilities/Timer/Timer.h"
#include "Input/KeyboardInput.h"
#include "Input/MouseInput.h"
#include "FileSystem/ResCache.h"

namespace liman {

	class ResCache;

	class BaseLogic;

	class GraphicsSystem;

	class Application {
	public:
		enum State {
			S_Invalid,
			S_Initializing,
			S_MainMenu,
			S_Loading,
			S_Running,
			S_Paused
		} m_state;

		virtual State VGetState() { return m_state; }

		virtual void VChangeState(State state) { m_state = state; }

	protected:
		bool m_bIsRunning;
		bool m_bIsEditorRunning;    // true if the game editor is running

	public:
		Application();

		~Application();

		virtual bool VInit();

		virtual void VDoLoop() {}

		virtual bool VDeInit() { return true; }

	public:
		bool InitResCache();

		bool InitSettings(std::string xmlFileName);

		bool IsRunning() { return m_bIsRunning; }

	public:
		virtual BaseLogic* GetGameLogic() { return m_pLogic; }

		GraphicsSystem* GetGraphicsSystem() { return m_pGraphicsSystem; }

		ResCache* GetResCahe() { return m_pResCache; }

		GameSettings* GetSettings() { return m_pSettings; }

		void SetKeyboard(KeyboardInput* pKeyboard) { m_pKeyboard = pKeyboard; }

		KeyboardInput* GetKeyboard() { return m_pKeyboard; }

		inline MouseInput* GetMouse() { return m_pMouse; }

		void SetTimer(Timer* pTimer) { m_pTimer = pTimer; }

		Timer* GetTimer() { return m_pTimer; }

	protected:
		BaseLogic* m_pLogic;
		//private:
		GraphicsSystem* m_pGraphicsSystem;
		ResCache* m_pResCache;
		GameSettings* m_pSettings;
		KeyboardInput* m_pKeyboard;
		MouseInput* m_pMouse;
		Timer* m_pTimer;
	};

	extern Application* g_pApp;

}