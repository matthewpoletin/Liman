#include "GraphicsSystem.h"

namespace liman {

	extern Application* g_pApp;

	GraphicsSystem::GraphicsSystem()
	{
		m_pDisplay = nullptr;
		m_pCamera = nullptr;
		m_pCamTransform = nullptr;
		m_pShaderManager = nullptr;
	}

	GraphicsSystem::~GraphicsSystem()
	{
		SAFE_DELETE(m_pCamTransform);
		SAFE_DELETE(m_pCamera);
		SAFE_DELETE(m_pDisplay);
		SAFE_DELETE(m_pShaderManager);
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
		m_pShaderManager = new ShaderManager();
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
		float colour = 1.0f;
		this->GetDisplay()->Clear(colour, colour, colour, 1.0f);

		ShaderList shaderList = m_pShaderManager->GetShaderList();
		auto iter = shaderList.begin();
		while (iter != shaderList.end())
		{
			Shader* pShader = m_pShaderManager->GetShader(iter->data());
			pShader->Bind();
			pShader->Update(*this->GetCameraTransform(), *this->GetCamera());
			for (ActorId id = INVALID_ACTOR_ID + 1; id <= (unsigned int)g_pBGL->GetLevelManager()->GetNumActors(); id++)
			{
				Renderable* pRend = g_pBGL->GetLevelManager()->GetActor(id)->GetComponent<Renderable>(Renderable::g_Name);
				TransformComponent* pTrans = g_pBGL->GetLevelManager()->GetActor(id)->GetComponent<TransformComponent>(TransformComponent::g_Name);
				if (pRend->GetShaderName() == iter->data())
				{
					pShader->Update(*pTrans->GetTransform(), *this->GetCamera());
					pRend->BindTexture();
					pRend->DrawMesh();
				}
			}
			iter++;
		}

		m_pDisplay->Update();
	}

}