#pragma once
// Editor.h : source file for the editor application and logic in C++


#include "Subsystems\Application.h"
#include "Subsystems\BaseGameLogic.h"

using namespace liman;

class EditorLogic;

class EditorApp : public Application
{
public:
	EditorApp() : Application() { m_bIsEditorRunning = true; }
	//TCHAR *VGetGameTitle() { return _T("GameCode4 Editor"); }
	//TCHAR *VGetGameAppDirectory() { return _T("Game Coding Complete 4\\Editor\\1.0"); }
	//HICON VGetIcon();

protected:
	BaseGameLogic *VCreateGameAndView();
};

class EditorLogic : public BaseGameLogic
{
public:
	EditorLogic();
	~EditorLogic();
	
	virtual bool VLoadGame(const char* levelName);
	const std::string &GetProjectDirectory(void) { return m_ProjectDirectory; }

	// We need to expose this information so that the C# app can
	// know how big of an array to allocate to hold the list of
	// actors
	int GetNumActors() { return (int)this->GetLevelManager()->m_actors.size(); }

	// Exposes the actor map so that the global functions
	// can retrieve actor information
	const ActorMap& GetActorMap() { return this->GetLevelManager()->m_actors; }

	bool IsRunning() { return (GS_Running == m_gameState); }

protected:
	std::string m_ProjectDirectory;
};

