#include "EditorLogic.h"

#include <direct.h>

namespace liman {

	EditorLogic::EditorLogic() : BaseGameLogic()
	{
		m_ProjectDirectory = getcwd(NULL, 0);
		int slashGamePos = m_ProjectDirectory.rfind("\\Game");
		m_ProjectDirectory = m_ProjectDirectory.substr(0, slashGamePos);

		//m_pPhysics.reset(CreateNullPhysics());
	}

	bool EditorLogic::VInit()
	{
		return true;
	}

	bool EditorLogic::VLoadGame(const char* levelName)
	{
		while (this->GetLevelManager()->m_actors.size() > 0)
		{
			ActorId id = this->GetLevelManager()->m_actors.begin()->first;
			this->GetLevelManager()->DestroyActor(id);
		}

		if (!BaseLogic::VLoadGame(levelName))
		{
			return false;
		}

		g_pApp->VChangeState(Application::State::S_Running);
		return true;
	}

	//shared_ptr<EditorHumanView> EditorLogic::GetHumanView() 
	//{
	//	GCC_ASSERT(m_gameViews.size()==1);
	//	shared_ptr<IGameView> pGameView = *m_gameViews.begin();
	//	shared_ptr<EditorHumanView> editorHumanView = static_pointer_cast<EditorHumanView>( pGameView );
	//	return editorHumanView; 
	//}

}