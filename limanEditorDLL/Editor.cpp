// Editor.cpp : source file for the editor application and logic in C++
#include "Editor.h"

#include "Actors/Actor.h"
#include "Utilities/Memory/Memory.h"

#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "advapi32.lib")			// useful for Windows Registry queries
#pragma comment(lib, "OleAut32.lib")			// needed for the C# / C++ BSTR conversions

//#pragma comment(lib, "zlibstat.lib")
//#pragma comment(lib, "libogg_static.lib")
//#pragma comment(lib, "libvorbis_static.lib")
//#pragma comment(lib, "libvorbisfile_static.lib")

//#pragma comment(lib, "tinyxml.lib")

//EditorApp globalApp;

namespace liman {

	EditorApp::EditorApp() : Game()
	{
		m_bIsEditorRunning = true;
	}

	bool EditorApp::VInit()
	{
		// TODO: add checking for editor in graphics initialization
		//Application::VInit();

		m_pLogic = new EditorLogic();
		if ((nullptr == m_pLogic) || !m_pLogic->VInit())
			return false;

		return true;
	}

	void EditorApp::VDoLoop()
	{
		// TODO:
	}

	bool EditorApp::VDeInit()
	{
		// TODO:
		return true;
	}

	//EditorLogic* EditorApp::VCreateGameAndView()
	//{
	//	EditorLogic* pLogic = NULL;

	//	pLogic = NEW EditorLogic();
	//	if (!pLogic->VInit())
	//	{
	//		LOG("", "some error occured");
	//		return nullptr;
	//	}

	//	//shared_ptr<IGameView> gameView(GCC_NEW EditorHumanView(g_pApp->m_Renderer));
	//	//game->VAddView(gameView);

	//	return pLogic;
	//}

	//HICON EditorApp::VGetIcon()
	//{
	//	return LoadIcon(GetInstance(), MAKEINTRESOURCE(IDI_ICON1));
	//}

}