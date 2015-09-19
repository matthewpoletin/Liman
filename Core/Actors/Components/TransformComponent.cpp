#include "TransformComponent.h"

#include "../../Utilities/Logger/Log.h"

#include <iostream>

namespace liman {

	const char*	TransformComponent::g_Name = "TransformComponent";

	TransformComponent::TransformComponent()
	{
		m_pTransform = new Transform();
	}

	bool TransformComponent::Init(tinyxml2::XMLElement* pComponentNode)
	{
		// Position
		tinyxml2::XMLElement* pPosNode = pComponentNode->FirstChildElement("Position");
		if (pPosNode)
		{
			pPosNode->QueryFloatAttribute("x", &m_pos.x);
			pPosNode->QueryFloatAttribute("y", &m_pos.y);
			pPosNode->QueryFloatAttribute("z", &m_pos.z);
		}
		else
		{
			LOG("ActorFactory", "Position loading failed");
			return false;
		}
		// Rotation
		tinyxml2::XMLElement* pRotNode = pComponentNode->FirstChildElement("Rotation");
		if (pRotNode)
		{
			pRotNode->QueryFloatAttribute("x", &m_rot.x);
			pRotNode->QueryFloatAttribute("y", &m_rot.y);
			pRotNode->QueryFloatAttribute("z", &m_rot.z);
		}
		else
		{
			LOG("ActorFactory", "Rotation loading failed");
			return false;
		}
		// Scale
		tinyxml2::XMLElement* pScaleNode = pComponentNode->FirstChildElement("Scale");
		if (pScaleNode)
		{
			pScaleNode->QueryFloatAttribute("x", &m_scale.x);
			pScaleNode->QueryFloatAttribute("y", &m_scale.y);
			pScaleNode->QueryFloatAttribute("z", &m_scale.z);
		}
		else
		{
			LOG("ActorFactory", "Scale loading failed");
			return false;
		}
		this->UpdateTransform();
		return true;
	}

	tinyxml2::XMLElement* TransformComponent::GenerateXML(tinyxml2::XMLDocument* outDoc)
	{
		tinyxml2::XMLElement* pTransNode = outDoc->NewElement(TransformComponent::g_Name);
		// Position
		tinyxml2::XMLElement* pPosNode = outDoc->NewElement("Position");
		pPosNode->SetAttribute("x", this->m_pos.x);
		pPosNode->SetAttribute("y", this->m_pos.y);
		pPosNode->SetAttribute("z", this->m_pos.z);
		pTransNode->InsertEndChild(pPosNode);
		// Rotation
		tinyxml2::XMLElement* pRotNode = outDoc->NewElement("Rotation");
		pRotNode->SetAttribute("x", this->m_rot.x);
		pRotNode->SetAttribute("y", this->m_rot.y);
		pRotNode->SetAttribute("z", this->m_rot.z);
		pTransNode->InsertEndChild(pRotNode);
		// Scale
		tinyxml2::XMLElement* pScaleNode= outDoc->NewElement("Scale");
		pScaleNode->SetAttribute("x", this->m_scale.x);
		pScaleNode->SetAttribute("y", this->m_scale.y);
		pScaleNode->SetAttribute("z", this->m_scale.z);
		pTransNode->InsertEndChild(pScaleNode);
		return pTransNode;
	}

	void TransformComponent::GetInfo()
	{
		std::cout << "Transform Component" << std::endl;
		std::cout << "Position: "	<< m_pos.x << ", " << m_pos.y << ", " << m_pos.z << std::endl;
		std::cout << "Rotation: "	<< m_rot.x << ", " << m_rot.y << ", " << m_rot.z << std::endl;
		std::cout << "Scale: "		<< m_scale.x << ", " << m_scale.y << ", " << m_scale.z << std::endl;
	}

	void TransformComponent::UpdateTransform()
	{
		m_pTransform->SetPos(glm::vec3(m_pos.x, m_pos.y, m_pos.z));
		m_pTransform->SetRot(glm::vec3(m_rot.x, m_rot.y, m_rot.z));
		m_pTransform->SetScale(glm::vec3(m_scale.x, m_scale.y, m_scale.z));
	}

	void TransformComponent::SetPos(float& posX, float& posY, float posZ)
	{
		m_pos = maths::Vec3f(posX, posY, posZ);
		this->UpdateTransform();
	}

	void TransformComponent::SetPos(maths::Vec2f& pos)
	{
		SetPos(pos.x, pos.y, m_pos.z);
	}

	void TransformComponent::SetPos(maths::Vec3f& pos)
	{
		m_pos = pos;
		this->UpdateTransform();
	}

	void TransformComponent::SetRot(float& posX, float& posY, float& posZ)
	{
		m_rot = maths::Vec3f(posX, posY, posZ);
		this->UpdateTransform();
	}

	void TransformComponent::SetRot(maths::Vec3f& rot)
	{
		m_rot = rot;
		this->UpdateTransform();
	}

	void TransformComponent::SetScale(float& posX, float& posY, float& posZ)
	{
		m_scale = maths::Vec3f(posX, posY, posZ);
		this->UpdateTransform();
	}

	void TransformComponent::SetScale(maths::Vec3f& scale)
	{
		m_scale = scale;
		this->UpdateTransform();
	}

}