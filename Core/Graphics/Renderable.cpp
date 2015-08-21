#include "Renderable.h"

#include "../Subsystems/Application.h"

namespace liman {

	const char* Renderable::g_Name = "RenderableComponent";

	extern Application* g_pApp;

	Renderable::Renderable(Actor* pOwner)
	{
		this->SetOwner(pOwner);
	}

	Renderable::~Renderable()
	{
		delete m_pTexture;
		delete m_pMesh;
	}

	void Renderable::Draw(void)
	{
		m_pTexture->Bind();
		m_pMesh->Draw();
	}

	void Renderable::SetTexture(std::string textureFileName)
	{
		m_texture = textureFileName;
		std::string texturePath = g_pApp->GetResCahe()->GetPath(PathType::Textures);
		std::string textureFile = texturePath + textureFileName;
		m_pTexture = new Texture(textureFile);
	}

}