#pragma once

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Camera.h"

extern Shader* g_pShader;

// TODO: create shaders handler
namespace liman {

	class GraphicsSystem
	{
	private:
		Display* m_pDisplay;
		Camera* m_pCamera;
		Transform* m_pCamTransform;

	public:
		GraphicsSystem();
		~GraphicsSystem();

		bool Init();

		void CheckErrors();

		void Draw();

		void SetDisplay(Display* pDisplay);
		Display* GetDisplay() { return m_pDisplay; }
		void SetCamera(Camera* pCamera) { m_pCamera = pCamera; }
		Camera* GetCamera() { return m_pCamera; }
		void SetCameraTransform(Transform* pTransform) { m_pCamTransform = pTransform; }
		Transform* GetCameraTransform() { return m_pCamTransform; }
	};

}