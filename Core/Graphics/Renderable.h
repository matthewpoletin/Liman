#pragma once
// Renderable.h - renderable component class

#include <string>

#include "../Actors/Actor.h"
#include "../Actors/ActorComponent.h"

#include "../Subsystems/Application.h"

#include <tinyxml2/tinyxml2.h>

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
		virtual bool Init(tinyxml2::XMLElement* pComponentNode) override;
		void Update(int deltaMS) override;
		virtual void GetInfo() override;
		
		virtual tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;

	public:
		Renderable();
		virtual ~Renderable();

	public:
		void SetMesh(Mesh* pMesh) { m_pMesh = pMesh; }
		Mesh* GetMesh() { return m_pMesh; }
		void UpdateMesh(void);

		void SetTexture(std::string texture);
		Texture* GetTexture() { return m_pTexture; }

		void BindTexture() { m_pTexture->Bind(); }
		void DrawMesh() { m_pMesh->Draw(); }

		std::string GetTextureName() { return m_texture; }
		void SetShaderName(std::string shaderName) { m_shaderName = shaderName; }
		std::string GetShaderName() { return m_shaderName; }

		bool HasTexture() { if (m_texture != "") return true; else return false; }

	private:
		std::string m_texture;
		std::string m_mesh;
		std::string m_shaderName;

		maths::Vec2f m_size;

		Texture* m_pTexture;
		Mesh* m_pMesh;

	};

}