#include "Renderable.h"

#include "../Actors/Components/TransformComponent.h"

namespace liman {

	const char* Renderable::g_Name = "RenderableComponent";

	extern Application* g_pApp;

	Renderable::Renderable()
	{
		m_pTexture = nullptr;
		m_pMesh = nullptr;
	}

	Renderable::~Renderable()
	{
		delete m_pTexture;
		delete m_pMesh;
	}

	bool Renderable::Init(tinyxml2::XMLElement* pComponentNode)
	{
		bool isTextureSet = false;
		//bool isColourSet = false;
		// Colour
		// TODO: Colour loading

		// Size
		tinyxml2::XMLElement* pSizeNode = pComponentNode->FirstChildElement("Size");
		if (pSizeNode)
		{
			pSizeNode->QueryFloatAttribute("x", &m_size.x);
			pSizeNode->QueryFloatAttribute("y", &m_size.y);
		}
		// Texture
		tinyxml2::XMLElement* textureNode = pComponentNode->FirstChildElement("Texture");
		if (textureNode != NULL)
		{
			isTextureSet = true;
			std::string texture = textureNode->Attribute("path");
			this->SetTexture(texture);
		}
		// Mesh
		Mesh* pMesh;
		tinyxml2::XMLElement* meshNode = pComponentNode->FirstChildElement("Model");
		if (meshNode != NULL)
		{
			std::string meshPathFileName = meshNode->Attribute("path");
			std::string meshPath = liman::g_pApp->GetResCahe()->GetPath("Models");
			std::string meshFile = meshPath + meshPathFileName;
			pMesh = new Mesh(meshFile);
			this->SetMesh(pMesh);
		}
		else
		{
			this->UpdateMesh();
		}
		return true;
	}

	tinyxml2::XMLElement* Renderable::GenerateXML(tinyxml2::XMLDocument* outDoc)
	{
		tinyxml2::XMLElement* pRendNode = outDoc->NewElement(Renderable::g_Name);
		// Texture
		tinyxml2::XMLElement* pTextureNode = outDoc->NewElement("Texture");
		pTextureNode->SetAttribute("path", m_texture.c_str());
		pRendNode->InsertEndChild(pTextureNode);
		// Mesh
		tinyxml2::XMLElement* pMeshNode = outDoc->NewElement("Velocity");
		pMeshNode->SetAttribute("path", m_mesh.c_str());
		pRendNode->InsertEndChild(pMeshNode);
		// Size
		tinyxml2::XMLElement* pSizeNode = outDoc->NewElement("Size");
		pSizeNode->SetAttribute("x", this->m_size.x);
		pSizeNode->SetAttribute("y", this->m_size.y);
		pRendNode->InsertEndChild(pSizeNode);
		return pRendNode;
	}

	void Renderable::Update(int deltaMS)
	{
		m_pTexture->Bind();
		m_pMesh->Draw();
	}

	void Renderable::GetInfo()
	{
		std::cout << g_Name << std::endl;
	}

	void Renderable::UpdateMesh(void)
	{
		if (!m_pOwner) { LOG("Renderable", "Host not found"); return; }
		TransformComponent* pTrans = m_pOwner->GetComponent<TransformComponent>(TransformComponent::g_Name);
		if (!pTrans) { LOG("ActorFactory", "Transform component not found"); return; }

		float posX = pTrans->GetPos().x;
		float posY = pTrans->GetPos().y;
		float posZ = pTrans->GetPos().z;
		float width		= m_size.x;
		float height	= m_size.y;
		float leftX		= posX - width / 2;
		float rightX	= posX + width / 2;
		float topY		= posY + height / 2;
		float bottomY	= posY - height / 2;

		Vertex vert0 = Vertex(glm::vec3(leftX, topY, posZ), glm::vec2(0, 0), glm::vec3(0, 0, 1));
		Vertex vert1 = Vertex(glm::vec3(leftX, bottomY, posZ), glm::vec2(0, 1), glm::vec3(0, 0, 1));
		Vertex vert2 = Vertex(glm::vec3(rightX, bottomY, posZ), glm::vec2(1, 1), glm::vec3(0, 0, 1));
		Vertex vert3 = Vertex(glm::vec3(rightX, topY, posZ), glm::vec2(1, 0), glm::vec3(0, 0, 1));

		Vertex vertices[] = { vert0, vert1, vert2, vert3 };
		unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };
		Mesh* pMesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
		this->SetMesh(pMesh);
	}

	void Renderable::SetTexture(std::string textureFileName)
	{
		m_texture = textureFileName;
		std::string texturePath = g_pApp->GetResCahe()->GetPath("Textures");
		std::string textureFile = texturePath + textureFileName;
		m_pTexture = new Texture(textureFile);
	}

}