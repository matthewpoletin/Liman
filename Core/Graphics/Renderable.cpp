#include "Renderable.h"

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

	bool Renderable::Init(tinyxml2::XMLElement* pComponentNode)
	{
		// Transform
		//Transform* pTransform = new Transform(glm::vec3(pActor->GetPosX(), pActor->GetPosY(), pActor->GetPosZ()), glm::vec3(1.0f), glm::vec3(scale));
		Transform* pTransform = new Transform;
		pTransform->SetPos(glm::vec3(m_pOwner->GetPosX(), m_pOwner->GetPosY(), m_pOwner->GetPosZ()));
		// Scale
		glm::vec3 scale(1.0f);
		tinyxml2::XMLElement* scaleNode = pComponentNode->FirstChildElement("Scale");
		if (scaleNode != NULL)
		{
			scale.x = std::stof(scaleNode->Attribute("x"));
			scale.y = std::stof(scaleNode->Attribute("y"));
			scale.z = std::stof(scaleNode->Attribute("z"));
		}
		pTransform->SetScale(scale);
		// Rotation
		glm::vec3 rotation(0.0f);
		tinyxml2::XMLElement* rotationNode = pComponentNode->FirstChildElement("Rotation");
		if (rotationNode != NULL)
		{
			rotation.x = std::stof(rotationNode->Attribute("x"));
			rotation.y = std::stof(rotationNode->Attribute("y"));
			rotation.z = std::stof(rotationNode->Attribute("z"));
		}

		pTransform->SetRot(rotation);
		this->SetTransform(pTransform);

		bool isTextureSet = false;
		//bool isColourSet = false;
		// Colour
		// TODO: Colour loading

		// Texture
		tinyxml2::XMLElement* textureNode = pComponentNode->FirstChildElement("Texture");
		if (textureNode != NULL)
		{
			isTextureSet = true;
			std::string texture = textureNode->Attribute("path");
			this->SetTexture(texture);
			/*			if ((pActor->GetWidth() == 0))
			pActor->SetWidth(rendComp->GetTexture()->GetWidth());
			if (pActor->GetHeight() == 0)
			pActor->SetHeight(rendComp->GetTexture()->GetHeight());*/
		}

		// Mesh
		Mesh* pMesh;
		tinyxml2::XMLElement* meshNode = pComponentNode->FirstChildElement("Mesh");
		if (meshNode != NULL)
		{
			std::string meshPathFileName = meshNode->Attribute("path");

			std::string meshPath = liman::g_pApp->GetResCahe()->GetPath(PathType::Meshes);
			std::string meshFile = meshPath + meshPathFileName;

			pMesh = new Mesh(meshFile);
		}
		else
		{
			float posX = m_pOwner->GetPosX();
			float posY = m_pOwner->GetPosY();
			float posZ = m_pOwner->GetPosZ();
			float width = m_pOwner->GetWidth();
			float height = m_pOwner->GetHeight();
			float leftX = posX - width / 2;
			float rightX = posX + width / 2;
			float topY = posY + height / 2;
			float bottomY = posY - height / 2;

			Vertex vert0 = Vertex(glm::vec3(leftX, topY, posZ), glm::vec2(0, 0), glm::vec3(0, 0, 1));
			Vertex vert1 = Vertex(glm::vec3(leftX, bottomY, posZ), glm::vec2(0, 1), glm::vec3(0, 0, 1));
			Vertex vert2 = Vertex(glm::vec3(rightX, bottomY, posZ), glm::vec2(1, 1), glm::vec3(0, 0, 1));
			Vertex vert3 = Vertex(glm::vec3(rightX, topY, posZ), glm::vec2(1, 0), glm::vec3(0, 0, 1));

			Vertex vertices[] = { vert0, vert1, vert2, vert3 };
			unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };
			pMesh = new Mesh(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
		}
		this->SetMesh(pMesh);

		return true;
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