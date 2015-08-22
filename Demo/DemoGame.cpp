#include "DemoGame.h"

#include "Utilities/Logger/Log.h"

#include "Actors/ActorFactory.h"
#include "Actors/Actor.h"
#include "Input/KeyboardInput.h"
#include "Subsystems/Application.h"
#include "Graphics/GraphicsSystem.h"

#include <Windows.h>

DemoGame* DemoGame::m_instance;

using namespace liman;

Shader* g_pShader;

DemoGame::DemoGame()
{
	if (!m_instance) m_instance = this;
}

DemoGame::~DemoGame()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = NULL;
	}
}

void DemoGame::Init()
{
	Log::Init("");
	LOG("Info", "Initializing subsystems");

#ifndef _DEBUG
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif
	liman::g_pApp = new Application();
	liman::g_pBGL = new BaseGameLogic();

	if (!liman::g_pApp->InitResCache())
	{
		LOG("Application", "initialization failed");
		return;
	}
	// TODO: Load path from settings
	liman::g_pApp->GetResCahe()->SetPath(PathType::Resources, "../../Assets");
	liman::g_pApp->GetResCahe()->SetPath(PathType::DevelopmentResources, "../../Assets");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Saves, "");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Settings, "Config/");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Shaders, "Shaders/");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Levels, "World/Levels/");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Entities, "World/Entities/");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Textures, "Graphics/Textures/");
	liman::g_pApp->GetResCahe()->SetPath(PathType::Meshes, "World/Models/");


	if (!liman::g_pApp->InitSettings("Settings.xml"))
	{
		LOG("Application", "initialization failed");
		return;
	}

	if (!liman::g_pApp->Init())
	{
		LOG("Application", "initialization failed");
		return;
	}
	
	liman::g_pBGL->Init();

	//g_pBGL->GetInputManager()->SetKey(GLFW_KEY_ESCAPE);
	//TODO: Move used keys init to settings loading/changing
	for (unsigned int keyCounter = 0; keyCounter < MAX_KEYS; keyCounter++)
	{
		g_pBGL->GetInputManager()->SetKey(keyCounter);
	}
	for (unsigned int buttonCounter = 0; buttonCounter < MAX_BUTTONS; buttonCounter++)
	{
		g_pBGL->GetInputManager()->SetKey(buttonCounter);
	}

	liman::g_pBGL->VLoadGame(liman::g_pApp->GetSettings()->level.c_str());

	liman::g_pBGL->GetLevelManager()->ShowListOfActors();
	liman::g_pBGL->GetLevelManager()->GetActorsInfo();

	g_pShader = new Shader(liman::g_pApp->GetResCahe()->GetPath(PathType::Shaders) + "basicShader");
}

void DemoGame::DoLoop()
{
	liman::g_pApp->GetTimer()->StartTimer();

	liman::g_pBGL->GetInputManager()->Update();

	TempInputReaction();

	//liman::g_pBGL->GetCollisionManager()->UpdateCollision();

	liman::g_pBGL->GetPhysicsManager()->UpdateMovables(liman::g_pApp->GetSettings()->display.msPerFrame);
	liman::g_pApp->GetGraphicsSystem()->Draw();

	liman::g_pApp->GetTimer()->StopTimer();
	if (liman::g_pApp->GetTimer()->GetDelta() < liman::g_pApp->GetSettings()->display.msPerFrame)
	{
		double sleepTimeMS = liman::g_pApp->GetSettings()->display.msPerFrame - liman::g_pApp->GetTimer()->GetDelta();
		Sleep((DWORD)sleepTimeMS);
	}
}

void DemoGame::DeInit()
{
	delete liman::g_pBGL;
	delete liman::g_pApp;
}

// ----
void TempInputReaction()
{
	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_A))
	{
		Renderable* pRend = liman::g_pBGL->GetLevelManager()->GetActor(1)->GetComponent<Renderable>(Renderable::g_Name);
		glm::vec3 rot = pRend->GetTransform()->GetRot();
		pRend->GetTransform()->SetRot(glm::vec3(rot.x, rot.y - 5.0f, rot.z));
	}

	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_D))
	{
		Renderable* pRend = liman::g_pBGL->GetLevelManager()->GetActor(1)->GetComponent<Renderable>(Renderable::g_Name);
		glm::vec3 rot = pRend->GetTransform()->GetRot();
		pRend->GetTransform()->SetRot(glm::vec3(rot.x, rot.y + 5.0f, rot.z));
	}

	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_W))
	{
		Renderable* pRend = liman::g_pBGL->GetLevelManager()->GetActor(1)->GetComponent<Renderable>(Renderable::g_Name);
		glm::vec3 rot = pRend->GetTransform()->GetRot();
		pRend->GetTransform()->SetRot(glm::vec3(rot.x - 5.0f, rot.y, rot.z));
	}

	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_S))
	{
		Renderable* pRend = liman::g_pBGL->GetLevelManager()->GetActor(1)->GetComponent<Renderable>(Renderable::g_Name);
		glm::vec3 rot = pRend->GetTransform()->GetRot();
		pRend->GetTransform()->SetRot(glm::vec3(rot.x + 5.0f, rot.y, rot.z));
	}

	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_RIGHT))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x + 10, pos.y, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes right");
	}
	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_LEFT))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x - 10, pos.y, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes left");
	}
	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_UP))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y + 10, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes up");
	}
	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_DOWN))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y - 10, pos.z), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes down");
	}
	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_SPACE))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y, pos.z + 10), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes forward");
	}
	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_LEFT_SHIFT))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(pos.x, pos.y, pos.z - 10), pCam->GetForward(), pCam->GetUp());

		LOG("Player", "Walkes backward");
	}

	if (liman::g_pBGL->GetInputManager()->IsKeyPressed(GLFW_KEY_ENTER))
	{
		Camera* pCam = liman::g_pApp->GetGraphicsSystem()->GetCamera();
		glm::vec3 pos = pCam->getPos();
		pCam->Move(glm::vec3(0.0f, 0.0f, 600.0f), pCam->GetForward(), pCam->GetUp());
	}

	if (liman::g_pBGL->GetInputManager()->IsKeyClicked(GLFW_KEY_ESCAPE))
	{
		liman::g_pApp->GetGraphicsSystem()->GetDisplay()->Close();
		LOG("Game", "Quiting");
	}

	if (liman::g_pBGL->GetInputManager()->IsButtonClicked(GLFW_MOUSE_BUTTON_LEFT))
	{
		LOG("Player", "Shoots");
	}
}

// -------------------

//if (pKeyboard->isKeyPressed(GLFW_KEY_W))
//{
//	LOG("Keyboard input", "Key W was pressed");
//	//OnUpPress();
//}
//if (pKeyboard->isKeyPressed(GLFW_KEY_S))
//{
//	LOG("Keyboard input", "Key S was pressed");
//	//OnDownPress();
//}
//if (pKeyboard->isKeyPressed(GLFW_KEY_A))
//{
//	LOG("Keyboard", "Key A was pressed");
//	//OnLeftPress();
//}
//if (pKeyboard->isKeyPressed(GLFW_KEY_D))
//{
//	LOG("Keyboard", "Key D was pressed");
//	//OnRightPress();
//}
//if (pKeyboard->isKeyTyped(GLFW_KEY_SPACE))
//{
//	LOG("Keyboard", "Key Space was pressed");
//	//OnJumpClick();
//}