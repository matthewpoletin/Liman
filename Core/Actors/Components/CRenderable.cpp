#include "CRenderable.h"

#include "../../Subsystems/Application.h"

namespace liman {

	extern Application* g_pApp;

	CRenderable::CRenderable(Actor* pOwner)
	{
		this->SetOwner(pOwner);
	}

	CRenderable::~CRenderable()
	{
		delete m_pTexture;
		delete m_pMesh;
	}

	void CRenderable::Draw(void)
	{
		m_pTexture->Bind();
		m_pMesh->Draw();
	}

	void CRenderable::SetTexture(std::string textureFileName)
	{
		m_texture = textureFileName;
		std::string texturePath = g_pApp->GetResCahe()->GetPath(PathType::Textures);
		std::string textureFile = texturePath + textureFileName;
		m_pTexture = new Texture(textureFile);
	}

}