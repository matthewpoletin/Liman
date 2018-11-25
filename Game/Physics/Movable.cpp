#include "Movable.h"

#include "Utilities/Logger/Log.h"

#include "Actors/Components/TransformComponent.h"

namespace liman {

	const char* Movable::g_Name = "MovableComponent";

	// TODO: pick up appropriate value
	// TODO: move to developer settings
	float Movable::g_gravity = 0.000098f;

	Movable::Movable() {
		m_vel.x = 0.0f;
		m_vel.y = 0.0f;

		m_accel.x = 0.0f;
		m_accel.y = 0.0f;

		m_isStatic = true;
		m_isFalling = false;
	}

	bool Movable::Init(tinyxml2::XMLElement* pComponentNode) {
		tinyxml2::XMLElement* velocityNode = pComponentNode->FirstChildElement("Velocity");
		if (!velocityNode) {
			LOG("Actor Factory", "Error: Velocity was not set.\n");
			this->SetVelocity(0.0f, 0.0f);
		} else {
			std::string tempVelStrX = velocityNode->Attribute("x") + (std::string) "f";
			std::string tempVelStrY = velocityNode->Attribute("y") + (std::string) "f";
			float velX = std::stof(tempVelStrX.c_str());
			float velY = std::stof(tempVelStrY.c_str());
			this->SetVelocity(velX, velY);
		}

		tinyxml2::XMLElement* accelNode = pComponentNode->FirstChildElement("Acceleration");
		if (!accelNode) {
			LOG("Actor Factory", "Error: Acceleration was not set.\n");
			this->SetAccel(0.0f, 0.0f);
		} else {
			std::string tempAcccelStrX = accelNode->Attribute("x") + (std::string) "f";
			std::string tempAcccelStrY = accelNode->Attribute("y") + (std::string) "f";
			float accelX = std::stof(tempAcccelStrX.c_str());
			float accelY = std::stof(tempAcccelStrY.c_str());
			this->SetAccel(accelX, accelY);
		}

		tinyxml2::XMLElement* fallingNode = pComponentNode->FirstChildElement("Falling");
		if (fallingNode) {
			std::string fallingValue = fallingNode->Attribute("value");
			if (fallingValue == "true") this->SetFalling(true);
			else this->SetFalling(false);
		}

		tinyxml2::XMLElement* staticNode = pComponentNode->FirstChildElement("Static");
		if (staticNode) {
			std::string staticValue = staticNode->Attribute("value");
			if (staticValue == "true") this->SetStatic(true);
			else this->SetStatic(false);
		}

		return true;
	}

	void Movable::Update(int deltaTimeMS) {
		TransformComponent* pTrans = m_pOwner->GetComponent<TransformComponent>(TransformComponent::g_Name);
		float posX = pTrans->GetPos().x;
		float posY = pTrans->GetPos().y;

		m_vel.x += m_accel.x * deltaTimeMS;
		if (!m_isFalling) {
			m_vel.y += m_accel.y * deltaTimeMS;
		} else {
			m_vel.y += (m_accel.y - g_gravity) * deltaTimeMS;
		}

		posX += m_vel.x * deltaTimeMS;
		posY += m_vel.y * deltaTimeMS;

		pTrans->SetPosX(posX);
		pTrans->SetPosY(posY);
//		pTrans->SetPos(maths::Vec2f(posX, posY));
	}

	void Movable::GetInfo() {
		std::cout << g_Name << std::endl;
		std::cout << "Velocity: " << m_vel.x << ", " << m_vel.y << ", " << /*m_vel.z << */std::endl;
		std::cout << "Acceleration: " << m_accel.x << ", " << m_accel.y << ", " << /*m_accel.z << */std::endl;
	}

	tinyxml2::XMLElement* Movable::GenerateXML(tinyxml2::XMLDocument* outDoc) {
		tinyxml2::XMLElement* pMoveNode = outDoc->NewElement(Movable::g_Name);
		// Velocity
		tinyxml2::XMLElement* pVelNode = outDoc->NewElement("Velocity");
		pVelNode->SetAttribute("x", this->m_vel.x);
		pVelNode->SetAttribute("y", this->m_vel.y);
		pMoveNode->InsertEndChild(pVelNode);
		// Acceleration
		tinyxml2::XMLElement* pAccelNode = outDoc->NewElement("Acceleration");
		pAccelNode->SetAttribute("x", this->m_accel.x);
		pAccelNode->SetAttribute("y", this->m_accel.y);
		pMoveNode->InsertEndChild(pAccelNode);
		// Falling
		tinyxml2::XMLElement* pFallingNode = outDoc->NewElement("Falling");
		if (m_isFalling)
			pFallingNode->SetAttribute("value", "true");
		else
			pFallingNode->SetAttribute("value", "false");
		pMoveNode->InsertEndChild(pFallingNode);
		// Static
		tinyxml2::XMLElement* pStaticNode = outDoc->NewElement("Static");
		if (m_isStatic)
			pStaticNode->SetAttribute("value", "true");
		else
			pStaticNode->SetAttribute("value", "false");
		pMoveNode->InsertEndChild(pStaticNode);
		return pMoveNode;
	}

}