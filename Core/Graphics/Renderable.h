#pragma once
// Renderable.h - renderable component class

#include <string>

#include "../Actors/Actor.h"
#include "../Actors/ActorComponent.h"

#include "Texture.h"
#include "Mesh.h"
#include "Transform.h"

namespace liman {

	class Renderable : public ActorComponent
	{
	public:
		static const char* g_Name;
		virtual const char* GetName() const override { return g_Name; }
		virtual ComponentId GetId(void) const override { return GetIdFromName(GetName()); }

	public:
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