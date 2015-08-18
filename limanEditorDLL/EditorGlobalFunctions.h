#pragma once
// EditorGlobalFunctions.h : exports game engine functions to C++ DLL

#define DllExport _declspec(dllexport)

#include "Editor.h"

#include <Windows.h>

// Editor Framework Functions
extern "C" DllExport int EditorMain(int *instancePtrAddress, int *hPrevInstancePtrAddress, int *hWndPtrAddress, int nCmdShow, int screenWidth, int screenHeight);
//extern "C" DllExport void WndProc(int *hWndPtrAddress, int msg, int wParam, int lParam);
extern "C" DllExport int IsGameRunning();
extern "C" DllExport void RenderFrame();
extern "C" DllExport int Shutdown();
extern "C" DllExport void OpenLevel( BSTR lFileName );

// Actor accessor functions
extern "C" DllExport int GetNumActors();
extern "C" DllExport void GetActorList( int *actorIdArrayPtrAddress, int size );
extern "C" DllExport int GetActorXmlSize ( ActorId actorId );
extern "C" DllExport void GetActorXml ( int *actorXmlPtrAddress, ActorId actorId );
//extern "C" DllExport int PickActor(int *hWndPtrAddress);

// Actor Modification functions
extern "C" DllExport int CreateActor( BSTR bstrActorResource );
extern "C" DllExport void ModifyActor ( BSTR bstrActorModificationXML );
extern "C" DllExport void DestroyActor( ActorId actorId );

// Level script additions - added post press
extern "C" DllExport int GetLevelScriptAdditionsXmlSize (  );
extern "C" DllExport void GetLevelScriptAdditionsXml ( int *xmlPtrAddress );