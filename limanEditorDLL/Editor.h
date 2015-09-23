#pragma once
// Editor.h : source file for the editor application and logic in C++

#include "Game.h"
#include "EditorLogic.h"

namespace liman {

	class Game;
	class BaseGameLogic;
	class EditorLogic;

	class EditorApp : public Game
	{
	public:
		EditorApp();
		virtual ~EditorApp() {}

	public:
		virtual bool VInit(void) override;
		virtual void VDoLoop(void) override;
		virtual bool VDeInit(void) override;

	//public:
		//TCHAR *VGetGameTitle() { return _T("GameCode4 Editor"); }
		//TCHAR *VGetGameAppDirectory() { return _T("Game Coding Complete 4\\Editor\\1.0"); }
		//HICON VGetIcon();
		//EditorLogic* VCreateGameAndView();

	};

}