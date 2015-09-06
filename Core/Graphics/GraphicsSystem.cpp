#include "GraphicsSystem.h"

#include "../Subsystems/Application.h"

#include "../Utilities/Memory/Memory.h"

#include "../Utilities/Logger/Log.h"

#include "../Actors/Actor.h"

#include "../Game.h"

#include "../Actors/Components/TransformComponent.h"

namespace liman {

	extern Application* g_pApp;

	GraphicsSystem::GraphicsSystem()
	{
		m_pDisplay = nullptr;
		m_pCamera = nullptr;
		m_pCamTransform = nullptr;
	}

	GraphicsSystem::~GraphicsSystem()
	{
		SAFE_DELETE(m_pCamTransform);
		SAFE_DELETE(m_pCamera);
		SAFE_DELETE(m_pDisplay);
	}

	bool GraphicsSystem::Init()
	{
		GameSettings settings = *g_pApp->GetSettings();
		DisplaySettings display = g_pApp->GetSettings()->display;

		m_pDisplay = NEW Display(display.width, display.height, settings.title.c_str(), false);
		if ((NULL == m_pDisplay))
		{
			return false;
		}
		m_pCamera = NEW Camera(display.camera.pos, display.camera.fov, (float)(display.width / display.height), display.camera.zNear, display.camera.zFar, display.camera.forward, display.camera.up);
		if ((NULL == m_pCamera))
		{
			return false;
		}
		m_pCamTransform = NEW Transform(glm::vec3(1.0f), glm::vec3(0.0f), glm::vec3(1.0f));
		if ((NULL == m_pCamTransform))
		{
			return false;
		}
		return true; 
	}

	void GraphicsSystem::CheckErrors()
	{
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::string errorStr = std::string((const char*)glewGetErrorString(error));
			//LOG("Error", "OpenGL Error: " + errorStr);
		}
	}

	void GraphicsSystem::Draw()
	{
		//float colour = (sinf(glfwGetTime()))* 0.4f;
		float colour = 1.0f;
		this->GetDisplay()->Clear(colour, colour, colour, 1.0f);

		g_pShader->Bind();
		g_pShader->Update(*this->GetCameraTransform(), *this->GetCamera());

		for (ActorId id = INVALID_ACTOR_ID + 1; id <= (unsigned int)g_pBGL->GetLevelManager()->GetNumActors(); id++)
		{
			Renderable* pRend = g_pBGL->GetLevelManager()->GetActor(id)->GetComponent<Renderable>(Renderable::g_Name);
			TransformComponent* pTrans = g_pBGL->GetLevelManager()->GetActor(id)->GetComponent<TransformComponent>(TransformComponent::g_Name);

			if (pRend)
			{
				g_pShader->Update(*pTrans->GetTransform(), *this->GetCamera());
				pRend->BindTexture();
				pRend->DrawMesh();
			}
		}

		this->GetDisplay()->Update();
	}

}