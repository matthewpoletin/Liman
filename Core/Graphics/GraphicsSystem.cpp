#include "GraphicsSystem.h"

#include "../Subsystems/Application.h"

#include "../Utilities/Memory/Memory.h"

#include "../Utilities/Logger/Log.h"

#include "../Actors/Actor.h"

#include "../Game.h"

#include <math.h>	//modf

namespace liman {

	extern Application* g_pApp;

	GraphicsSystem::GraphicsSystem()
	{
		m_pDisplay = NULL;
		m_pCamera = NULL;
		m_pCamTransform = NULL;
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

		m_pDisplay = new Display(display.width, display.height, settings.title.c_str(), false);
		if ((NULL == m_pDisplay))
		{
			return false;
		}
		m_pCamera = new Camera(display.camera.pos, display.camera.fov, (float)(display.width / display.height), display.camera.zNear, display.camera.zFar, display.camera.forward, display.camera.up);
		if ((NULL == m_pCamera))
		{
			return false;
		}
		m_pCamTransform = new Transform(glm::vec3(1.0f), glm::vec3(0.0f), glm::vec3(1.0f));
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
		liman::g_pApp->GetGraphicsSystem()->GetDisplay()->Clear(colour, colour, colour, 1.0f);

		////

		//struct LineSegment_t
		//{
		//	float x1, y1;
		//	float r1, g1, b1, a1;
		//	float x2, y2;
		//	float r2, g2, b2, a2;
		//};

		//int num_verts = lines.size() * 2;
		//glBindVertexArray(line_vao); // setup for the layout of LineSegment_t
		//glBindBuffer(GL_ARRAY_BUFFER, LineBufferObject);
		//glBufferData(GL_ARRAY_BUFFER, sizeof(LineSegment_t) / 2 * num_verts, &lines[0], GL_DYNAMIC_DRAW);
		//glDrawArrays(GL_LINES, 0, num_verts);
		////

		g_pShader->Bind();
		g_pShader->Update(*liman::g_pApp->GetGraphicsSystem()->GetCameraTransform(), *liman::g_pApp->GetGraphicsSystem()->GetCamera());

		CRenderable* pRend = NULL;
		for (ActorId id = INVALID_ACTOR_ID + 1; id <= (unsigned int)g_pBGL->GetLevelManager()->GetNumActors(); id++)
		{
			g_pBGL->GetLevelManager()->GetActor(id)->GetComponent(RENDERABLE, &pRend);
			if (pRend != NULL)
			{
				g_pShader->Update(*pRend->GetTransform(), *liman::g_pApp->GetGraphicsSystem()->GetCamera());
				pRend->BindTexture();
				pRend->DrawMesh();
			}
		}

		liman::g_pApp->GetGraphicsSystem()->GetDisplay()->Update();
	}

}