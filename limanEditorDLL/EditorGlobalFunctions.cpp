// EditorGlobalFunctions.cpp : exports game engine functions to C++ DLL

#include "EditorGlobalFunctions.h"

//#include "GCC4EditorStd.h"
//#include "..\..\GCC4\Graphics3D\Raycast.h"
//#define INVALID_ID -1;

#include <string>

#include "Actors/ActorFactory.h"
#include "Actors/ActorComponent.h"
#include "Utilities/logger/Log.h"
#include "Utilities/String/String.h"
#include "Utilities/Memory/Memory.h"

#include <tinyxml2/tinyxml2.h>

using namespace liman;

int EditorMain(int *instancePtrAddress, int *hPrevInstancePtrAddress, int *hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight)
{
   // C# passes HINSTANCE and HWND values to C++ DLL as (int *)
	HINSTANCE hInstance = (HINSTANCE)instancePtrAddress;
	HINSTANCE hPrevInstance = (HINSTANCE) hPrevInstancePtrAddress;
	HWND hWnd = (HWND)hWndPtrAddress;
	WCHAR *lpCmdLine = L"";

	// Set up checks for memory leaks.
	int tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	// set this flag to keep memory blocks around
	tmpDbgFlag |= _CRTDBG_DELAY_FREE_MEM_DF;				// this flag will cause intermittent pauses in your game!

	// perform memory check for each alloc/dealloc
	//tmpDbgFlag |= _CRTDBG_CHECK_ALWAYS_DF;				// remember this is VERY VERY SLOW!

	// always perform a leak check just before app exits.
	tmpDbgFlag |= _CRTDBG_LEAK_CHECK_DF;					

	_CrtSetDbgFlag(tmpDbgFlag);

    // Initialize the logging system as the very first thing you ever do!   LOL after the memory system flags are set, that is!
	Log::Init("");
    //Log::Init("logging.xml");
	liman::g_pApp = new Application();
	liman::g_pBGL = new BaseGameLogic();

	// Perform application initialization
	if (!liman::g_pApp->InitResCache())
	{
		LOG("Application", "initialization failed");
		return -1;
	}

#ifdef DEBUG
	std::string path = "../../../Assets/Paths.xml";
#else
	std::string path = "Resources/Paths.xml";
#endif

	if (!liman::g_pApp->GetResCahe()->LoadPaths(path))
	{
		LOG("Resource Cache", "Loading paths failed");
		return -1;
	}

	if (!liman::g_pApp->GetSettings()->Init("Settings.xml"))
	{
		LOG("Application", "Options loading failed");
		return 0;
	}

	if (!liman::g_pApp->InitSettings("Settings.xml"))
	{
		LOG("Application", "initialization failed");
		return -1;
	}

	if (!liman::g_pApp->Init())
	{
		LOG("Application", "initialization failed");
		return -1;
	}

	liman::g_pBGL->Init();

	for (unsigned int keyCounter = 0; keyCounter < MAX_KEYS; keyCounter++)
	{
		g_pBGL->GetInputManager()->SetKey(keyCounter);
	}
	for (unsigned int buttonCounter = 0; buttonCounter < MAX_BUTTONS; buttonCounter++)
	{
		g_pBGL->GetInputManager()->SetKey(buttonCounter);
	}

	liman::g_pApp->GetGraphicsSystem()->GetShaderManager()->CreateShader("basicShader");

	return 1;
}

void RenderFrame()
{
	// In TeapotWars, this would be called by GameCode's main loop
	// Since the C# app has its own main loop, we expose this
	// function so that C# app can call from its main loop
	g_pApp->GetGraphicsSystem()->Draw();
}

int Shutdown()
{
	// Normally this is called after the GameCode main loop ends. We
	// expose this here so that the C# app can shutdown after it finishes
	// its main loop

	SAFE_DELETE(liman::g_pApp);

	return 1;
}

//void WndProc(int *hWndPtrAddress, int msg, int wParam, int lParam)
//{
//	HWND hWnd = (HWND)hWndPtrAddress;
//	DXUTStaticWndProc( hWnd, msg, WPARAM(wParam), LPARAM(lParam) );
//}

int IsGameRunning()
{
	EditorLogic* game = (EditorLogic*)g_pApp->GetGameLogic();
   return (game) ? game->IsRunning() : false;
}

// TODO: This should return a bool specifying if the level was successfully opened.
void OpenLevel(BSTR fullPathLevelFile)
{
	//liman::g_pBGL->VLoadGame(liman::g_pApp->GetSettings()->level.c_str());

	// We need to strip off the project directory from the filename first.
	std::string levelFile = ws2s(std::wstring(fullPathLevelFile, SysStringLen(fullPathLevelFile))); 
	EditorLogic* pEditorLogic = (EditorLogic*)g_pApp->GetGameLogic();
	if (pEditorLogic)
	{
		std::string assetsDir = "\\Assets\\";
		int projDirLength = pEditorLogic->GetProjectDirectory().length() + assetsDir.length();
		g_pApp->GetSettings()->level = levelFile.substr(projDirLength, levelFile.length()-projDirLength);
		pEditorLogic->ChangeGameState(GS_LoadingGameEnvironment);
	}
}

int GetNumActors()
{
	EditorLogic* pGame = (EditorLogic*)g_pApp->GetGameLogic();
	return (pGame) ? pGame->GetNumActors() : 0;
}

void GetActorList( int *ptr, int numActors )
{
	// To keep things simple, we pass the actor ids to the C# app
	// the C# app iterates through the actor ids, and calls back into
	// the unmanaged dll to get the appropriate information about each
	// actor
	EditorLogic* pGame = (EditorLogic*)g_pApp->GetGameLogic();
	if ( pGame )
	{
		ActorMap::const_iterator itr;
		int actorArrayIndex;
		for ( itr = pGame->GetActorMap().begin(), actorArrayIndex = 0; 
			itr != pGame->GetActorMap().end() && actorArrayIndex < numActors; itr++, actorArrayIndex++ )
		{
			ActorId actorId = itr->first;
			ptr[actorArrayIndex] = actorId;
		}
	}
}

int GetActorXmlSize ( ActorId actorId )
{
	Actor* pActor = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(actorId);
	if ( !pActor )
	{
		return 0;
	}
	std::string xml = pActor->ToXML();
	return xml.length();
}

void GetActorXml ( int *actorXMLAddress, ActorId actorId )
{
	Actor* pActor = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(actorId);
	if ( !pActor )
	{
		return;
	}
	std::string xml = pActor->ToXML();
	
	strncpy_s(reinterpret_cast<char *>(actorXMLAddress), xml.length()+1, xml.c_str(), xml.length());
}

//int PickActor(int *hWndPtrAddress)
//{
//	HWND hWnd = (HWND)hWndPtrAddress;
//
//	POINT ptCursor;
//	GetCursorPos( &ptCursor );
//	
//	// Convert the screen coordinates of the mouse cursor into
//	// coordinates relative to the client window
//	ScreenToClient( hWnd, &ptCursor );
//	RayCast rayCast(ptCursor);
//	EditorLogic* pGame = (EditorLogic*)g_pApp->GetGameLogic();
//
//	if (!pGame)
//	{
//		return INVALID_ACTOR_ID;
//	}
//
//	shared_ptr<EditorHumanView> pView = pGame->GetHumanView();
//	if (!pView)
//	{
//		return INVALID_ACTOR_ID;
//	}
//
//
//	// Cast a ray through the scene. The RayCast object contains an array of Intersection
//	// objects.
//	pView->GetScene()->Pick(&rayCast);
//	rayCast.Sort();
//	
//	// If there are any intersections, get information from the first intersection.
//   if (!rayCast.m_NumIntersections)
//   {
//      return INVALID_ACTOR_ID;
//   }
//
//   Intersection firstIntersection = rayCast.m_IntersectionArray[0];
//   return firstIntersection.m_actorId;
//}

int CreateActor(BSTR bstrActorXMLFile)
{
	std::string actorResource = ws2s(std::wstring(bstrActorXMLFile, SysStringLen(bstrActorXMLFile))); 
	/*Actor* pActor = */g_pApp->GetGameLogic()->GetLevelManager()->LoadActor(actorResource);
	//if (!pActor)
	//	return INVALID_ACTOR_ID;

	// fire an event letting everyone else know that we created a new actor
	//shared_ptr<EvtData_New_Actor> pNewActorEvent(GCC_NEW EvtData_New_Actor(pActor->GetId()));
	//IEventManager::Get()->VQueueEvent(pNewActorEvent);
	//return pActor->GetId();
	return 1;
}


//void ModifyActor (BSTR bstrActorModificationXML)
//{
//	std::string actorModificationXML = ws2s(std::wstring(bstrActorModificationXML, SysStringLen(bstrActorModificationXML))); 
//
//	tinyxml2::XMLDocument doc;
//	doc.Parse(actorModificationXML.c_str());
//	tinyxml2::XMLElement* pRoot = doc.RootElement();
//    if (!pRoot)
//        return;
//
//	//g_pApp->GetGameLogic()->GetLevelManager()->ModifyActor(atoi(pRoot->Attribute("id")), pRoot);
//}

void DestroyActor( ActorId actorId )
{
	g_pApp->GetGameLogic()->GetLevelManager()->DestroyActor(actorId);
}

//int GetLevelScriptAdditionsXmlSize ( )
//{
//	TiXmlDocument *optionsDoc = g_pApp->m_Options.m_pDoc;
//	TiXmlElement *pRoot = optionsDoc->RootElement();
//    if (!pRoot)
//		return 0;
//
//	TiXmlElement *worldScriptAdditions = pRoot->FirstChildElement("WorldScriptAdditions");
//
//	TiXmlDocument outDoc;
//	TiXmlNode *node = worldScriptAdditions->Clone();
//    outDoc.LinkEndChild(node);
//
//	TiXmlPrinter printer;
//	outDoc.Accept(&printer);
//
//	std::string xml = printer.CStr();
//
//	return xml.length();
//}

//void GetLevelScriptAdditionsXml ( int *xmlAddress )
//{
//	TiXmlDocument *optionsDoc = g_pApp->m_Options.m_pDoc;
//	TiXmlElement *pRoot = optionsDoc->RootElement();
//    if (!pRoot)
//		return;
//
//	TiXmlElement *worldScriptAdditions = pRoot->FirstChildElement("WorldScriptAdditions");
//
//	TiXmlDocument outDoc;
//	TiXmlNode *node = worldScriptAdditions->Clone();
//    outDoc.LinkEndChild(node);
//
//
//	TiXmlPrinter printer;
//	outDoc.Accept(&printer);
//
//	std::string xml = printer.CStr();
//
//	strncpy_s(reinterpret_cast<char *>(xmlAddress), xml.length()+1, xml.c_str(), xml.length());
//}