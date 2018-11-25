#pragma once

#include "Editor.h"
#include "Logic/BaseGameLogic.h"

namespace liman {

	class EditorLogic : public BaseGameLogic
	{
	public:
		EditorLogic();
		virtual ~EditorLogic() {}
	
	public:
		bool IsRunning() { return (Application::State::S_Running == g_pApp->m_state); }

	public:
		virtual bool VInit(void) override;

	public:
		virtual bool VLoadGame(const char* levelName);
		const std::string &GetProjectDirectory(void) { return m_ProjectDirectory; }

	public:
		int GetNumActors() { return (int)m_pLevelManager->m_actors.size(); }
		const ActorMap& GetActorMap() { return m_pLevelManager->m_actors; }

	protected:
		std::string m_ProjectDirectory;

	};

}