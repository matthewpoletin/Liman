#include "Actor.h"

#include "../Graphics/Renderable.h"

#include "../Utilities/Logger/Log.h"

namespace liman {

	Actor::Actor()
	{
		m_type = NULL_TYPE;

		m_pos.x = 0.0f;
		m_pos.y = 0.0f;
		m_pos.z = 0.0f;

		m_size.x = 0.0f;
		m_size.y = 0.0f;

		//for (unsigned int counter = 0; counter < NUM_COMPONENTS; counter++)
		//	m_pComps[counter] = nullptr;
	}

	Actor::~Actor()
	{
		this->Destroy();
	}

	bool Actor::Init(tinyxml2::XMLElement* thisPropNode)
	{
		tinyxml2::XMLElement* typeNode = thisPropNode->FirstChildElement("Type");
		if (typeNode)
		{
			std::string attribute;

			attribute = typeNode->Attribute("value");
			if (attribute == "player")
			{
				g_pBGL->GetLevelManager()->SetPlayerId(this->GetId());
				this->SetType(ActorType::PLAYER);
			}
			//else if (typeValue == "GUI")
			//{
			//	this->SetType(GUI);
			//}
			//else if (typeValue == "ENEMY")
			//{
			//	this->SetType(ENEMY);
			//}
		}

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
		//for (unsigned int counter = 0; counter < NUM_COMPONENTS; counter++)
		//	delete m_pComps[counter];
		m_components.clear();
	}

	void Actor::AddComponent(ActorComponent* pComponent)
	{
		std::pair<ComponentsMap::iterator, bool> success = m_components.insert(std::make_pair(pComponent->GetId(), pComponent));
		assert(success.second);
	}

	void Actor::SetPos(float& posX, float& posY, float posZ)
	{
		//m_pos.x = posX;
		//m_pos.y = posY;
		//m_pos.z = posZ;

		//if (m_pComps[RENDERABLE] != nullptr)
		//{
		//	Renderable* rendComp;
		//	this->GetComponent(RENDERABLE, &rendComp);

		//	rendComp->GetTransform()->SetPos(glm::vec3(m_pos.x,m_pos.y, m_pos.z));
		//}
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
		tinyxml2::XMLDocument outDoc;

		//tinyxml2::XMLElement* thisElement = NEW tinyxml2::XMLElement(outDoc);
		//thisElement->SetName("Actor");
		//thisElement->SetAttribute("type", m_type.c_str());
		//thisElement->SetAttribute("resourc e", m_resource.c_str());

		// components
		/*for (auto it = m_components.begin(); it != m_components.end(); ++it)
		{
			ActorComponent* pComponent = it->second;
			tinyxml2::XMLElement* pComponentElement = pComponent->VGenerateXml();
			thisElement->LinkEndChild(pComponentElement);
		}

		outDoc.LinkEndChild(thisElement);
		*/tinyxml2::XMLPrinter printer;
		outDoc.Accept(&printer);

		return printer.CStr();
	}


}