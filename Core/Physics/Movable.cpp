#include "Movable.h"

#include "../Utilities/Logger/Log.h"

namespace liman {

	const char* Movable::g_Name = "Movable";

	// TODO: pick up appropriate value
	// TODO: move to developer settings
	float Movable::g_gravity = 0.000098f;

	Movable::Movable(Actor* pOwner)
	{
		this->SetOwner(pOwner);

		m_isStatic = true;
		m_isFalling = false;
	}

	Movable::~Movable()
	{

	}

	bool Movable::Init(tinyxml2::XMLElement* pComponentNode)
	{
		tinyxml2::XMLElement* velocityNode = pComponentNode->FirstChildElement("Velocity");
		if (!velocityNode)
		{
			LOG("Actor Factory", "Error: Velocity was not set.\n");
			this->SetVelocity(0.0f, 0.0f);
		}
		else
		{
			std::string tempVelStrX = velocityNode->Attribute("x") + (std::string)"f";
			std::string tempVelStrY = velocityNode->Attribute("y") + (std::string)"f";
			float velX = std::stof(tempVelStrX.c_str());
			float velY = std::stof(tempVelStrY.c_str());
			this->SetVelocity(velX, velY);
		}

		tinyxml2::XMLElement* accelNode = pComponentNode->FirstChildElement("Acceleration");
		if (!accelNode)
		{
			LOG("Actor Factory", "Error: Acceleration was not set.\n");
			this->SetAccel(0.0f, 0.0f);
		}
		else
		{
			std::string tempAcccelStrX = accelNode->Attribute("x") + (std::string)"f";
			std::string tempAcccelStrY = accelNode->Attribute("y") + (std::string)"f";
			float accelX = std::stof(tempAcccelStrX.c_str());
			float accelY = std::stof(tempAcccelStrY.c_str());
			this->SetAccel(accelX, accelY);
		}

		tinyxml2::XMLElement* fallingNode = pComponentNode->FirstChildElement("Falling");
		if (fallingNode)
		{
			std::string fallingValue = fallingNode->Attribute("value");
			if (fallingValue == "true") this->SetFalling(true);
			else this->SetFalling(false);
		}

		tinyxml2::XMLElement* staticNode = pComponentNode->FirstChildElement("Static");
		if (staticNode)
		{
			std::string staticValue = staticNode->Attribute("value");
			if (staticValue == "true") this->SetStatic(true);
			else  this->SetStatic(false);
		}

		return true;
	}

	void Movable::MoveX(float offset)
	{
		m_pOwner->m_pos.x += offset;
	}

	void Movable::MoveY(float offset)
	{
		m_pOwner->m_pos.y += offset;
	}

	void Movable::OnUpdate(float deltaTimeMS)
	{
		float deltaTimeS = 1000 * deltaTimeMS;

		float posX = m_pOwner->m_pos.x;
		float posY = m_pOwner->m_pos.y;

		m_velocityX += m_accelX * deltaTimeMS;
		if (!m_isFalling)
		{
			m_velocityY += m_accelY * deltaTimeMS;
		}
		else
		{
			m_velocityY += (m_accelY - g_gravity) * deltaTimeMS;
		}

		posX += m_velocityX * deltaTimeMS;
		posY += m_velocityY * deltaTimeMS;

		m_pOwner->SetPos(posX, posY, m_pOwner->GetPosZ());
	}

}