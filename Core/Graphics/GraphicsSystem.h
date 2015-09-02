#pragma once

#include "Display.h"

#include "ShaderManager.h"
#include "Shader.h"

#include "../Actors/Actor.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"

#include "../Game.h"
#include "../Subsystems/Application.h"

#include "../Utilities/Memory/Memory.h"
#include "../Utilities/Logger/Log.h"


namespace liman {

	class Application;
	class ShaderManager;

	class GraphicsSystem
	{
	private:
		Display* m_pDisplay;
		Camera* m_pCamera;
		Transform* m_pCamTransform;
		ShaderManager* m_pShaderManager;

	public:
		GraphicsSystem();
		~GraphicsSystem();

		bool Init();

		void CheckErrors();

		void Draw();

		void SetDisplay(Display* pDisplay);
		Display* GetDisplay() { return m_pDisplay; }
		ShaderManager* GetShaderManager() { return m_pShaderManager; }
		void SetCamera(Camera* pCamera) { m_pCamera = pCamera; }
		Camera* GetCamera() { return m_pCamera; }
		void SetCameraTransform(Transform* pTransform) { m_pCamTransform = pTransform; }
		Transform* GetCameraTransform() { return m_pCamTransform; }
	};

}