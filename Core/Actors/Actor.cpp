#include "Actor.h"

#include "../Graphics/Renderable.h"

#include "../Utilities/Logger/Log.h"

namespace liman {

	Actor::Actor()
	{
		m_pos.x = 0.0f;
		m_pos.y = 0.0f;
		m_pos.z = 0.0f;

		m_size.x = 0.0f;
		m_size.y = 0.0f;
	}

	Actor::~Actor()
	{
		this->Destroy();
	}

	bool Actor::Init(tinyxml2::XMLElement* thisPropNode)
	{
		tinyxml2::XMLElement* positionNode = thisPropNode->FirstChildElement("Position");
		if (!positionNode)
		{
			LOG("Actor Factory", "position loading failed");
			return false;
		}
		else
		{
			float x = 0;
			float y = 0;
			float z = 0;
			
			positionNode->QueryFloatAttribute("x", &x);
			positionNode->QueryFloatAttribute("y", &y);
			positionNode->QueryFloatAttribute("z", &z);

			this->SetPos(x, y, z);
		}

		tinyxml2::XMLElement* sizeNode = thisPropNode->FirstChildElement("Size");
		if (!sizeNode)
		{
			LOG("Actor Factory", "size loading failed");
			return false;
		}
		else
		{
			std::string tempSizeX = sizeNode->Attribute("x") + (std::string)"f";
			std::string tempSizeY = sizeNode->Attribute("y") + (std::string)"f";
			float sizeX = std::stof(tempSizeX.c_str());
			float sizeY = std::stof(tempSizeY.c_str());
			this->SetSize(maths::Vec2f(sizeX, sizeY));
		}

		return true;
	}

	void Actor::Destroy()
	{
		m_components.clear();
	}

	void Actor::AddComponent(ActorComponent* pComponent)
	{
		std::pair<ComponentsMap::iterator, bool> success = m_components.insert(std::make_pair(pComponent->GetId(), pComponent));
		assert(success.second);
	}

	void Actor::SetPos(float& posX, float& posY, float posZ)
	{
		m_pos.x = posX;
		m_pos.y = posY;
		m_pos.z = posZ;

		Renderable* pRendComp = this->GetComponent<Renderable>(Renderable::g_Name);

		if (pRendComp)
		{
			pRendComp->GetTransform()->SetPos(glm::vec3(m_pos.x,m_pos.y, m_pos.z));
		}
	}

	void Actor::SetPos(maths::Vec2f& vec2)
	{
		SetPos(vec2.x, vec2.y, 0.0f);
	}

	void Actor::SetPos(maths::Vec3f& vec3)
	{
		SetPos(vec3.x, vec3.y, vec3.z);
	}

	std::string Actor::ToXML()
	{
		tinyxml2::XMLDocument* outDoc = new tinyxml2::XMLDocument();
		tinyxml2::XMLElement* pActorNode = outDoc->NewElement("Actor");
		pActorNode->SetAttribute("resource", m_sourceName.c_str());
		tinyxml2::XMLElement* pPropNode = outDoc->NewElement("Properties");
		// Position
		tinyxml2::XMLElement* pPosNode = outDoc->NewElement("Position");
		pPosNode->SetAttribute("x", this->m_pos.x);
		pPosNode->SetAttribute("y", this->m_pos.y);
		pPosNode->SetAttribute("z", this->m_pos.z);
		pPropNode->InsertEndChild(pPosNode);
		// Size
		tinyxml2::XMLElement* pSizeNode = outDoc->NewElement("Size");
		pSizeNode->SetAttribute("x", this->m_size.x);
		pSizeNode->SetAttribute("y", this->m_size.y);
		pPropNode->InsertEndChild(pSizeNode);
		pActorNode->InsertEndChild(pPropNode);
		// Components
		tinyxml2::XMLElement* pCompNode = outDoc->NewElement("Components");
		for (auto it = m_components.begin(); it != m_components.end(); ++it)
		{
			ActorComponent* pComponent = it->second;
			tinyxml2::XMLElement* pComponentElement = pComponent->GenerateXML(outDoc);
			pCompNode->LinkEndChild(pComponentElement);
		}
		pActorNode->InsertEndChild(pCompNode);
		outDoc->InsertFirstChild(pActorNode);

		tinyxml2::XMLPrinter printer;
		outDoc->Accept(&printer);
		return printer.CStr();
	}


}