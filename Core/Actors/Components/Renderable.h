#pragma once
// Renderable.h - renderable component class

#include <string>

#include "../Actor.h"
#include "ActorComponent.h"

#include "../../Graphics/Texture.h"
#include "../../Graphics/Mesh.h"
#include "../../Graphics/Transform.h"

namespace liman {

	class Renderable : public ActorComponent
	{
	public:
		static const char* g_Name;
		virtual const char* VGetName() const { return g_Name; }

		Renderable(Actor* pOwner);
		~Renderable();

		void Draw();

		void SetMesh(Mesh* pMesh) { m_pMesh = pMesh; }
		Mesh* GetMesh() { return m_pMesh; }

		void SetTexture(std::string texture);
		Texture* GetTexture() { return m_pTexture; }

		void SetTransform(Transform* pTransform) { m_pTransform = pTransform; }
		Transform* GetTransform() { return m_pTransform; }

		void BindTexture() { m_pTexture->Bind(); }
		void DrawMesh() { m_pMesh->Draw(); }

		std::string GetTextureName() { return m_texture; }

		bool HasTexture() { if (m_texture != "") return true; else return false; }

	private:
		std::string m_texture;

		Texture* m_pTexture;
		Mesh* m_pMesh;
		Transform* m_pTransform;

	};

}