#include <iostream>

#include "../Graphics/Mesh.h"

#include "ActorFactory.h"

#include "../Utilities/Logger/Log.h"

#include "../Collisions/Rectangle.h"

#include "../Subsystems/Application.h"

namespace liman {

	ActorFactory::ActorFactory()
	{
		m_numActors = 0;
		m_lastActorId = INVALID_ACTOR_ID;
	}

	Actor* ActorFactory::CreateActor(tinyxml2::XMLElement* actorNode, std::string sourceName)
	{
		Actor* pActor = new Actor;
		pActor->SetId(GetNextActorId());
		pActor->SetSource(sourceName);

		std::string attribute;

		tinyxml2::XMLElement* propertiesNode = actorNode->FirstChildElement("Properties");
		if (!propertiesNode)
		{
			LOG("Actor Factory", "Failed to load actor properties");
			return NULL;
		}
		else
		{
			tinyxml2::XMLElement* typeNode = propertiesNode->FirstChildElement("Type");
			if (typeNode)
			{
				attribute = typeNode->Attribute("value");
				if (attribute == "player")
				{
					g_pBGL->GetLevelManager()->SetPlayerId(pActor->GetId());
					pActor->SetType(ActorType::PLAYER);
				}
				//else if (typeValue == "GUI")
				//{
				//	pActor->SetType(GUI);
				//}
				//else if (typeValue == "ENEMY")
				//{
				//	pActor->SetType(ENEMY);
				//}
			}

			tinyxml2::XMLElement* positionNode = propertiesNode->FirstChildElement("Position");
			if (!positionNode)
			{
				LOG("Actor Factory", "position loading failed");
				return NULL;
			}
			else
			{
				std::string tempPosX = positionNode->Attribute("x") + (std::string)"f";
				std::string tempPosY = positionNode->Attribute("y") + (std::string)"f";
				std::string tempPosZ = positionNode->Attribute("z") + (std::string)"f";
				float posX = std::stof(tempPosX.c_str());
				float posY = std::stof(tempPosY.c_str());
				float posZ = std::stof(tempPosZ.c_str());
				pActor->SetPosX(posX);
				pActor->SetPosY(posY);
				pActor->SetPosZ(posZ);
			}

			tinyxml2::XMLElement* sizeNode = propertiesNode->FirstChildElement("Size");
			if (!sizeNode)
			{
				LOG("Actor Factory", "size loading failed");
				return NULL;
			}
			else
			{
				std::string tempSizeX = sizeNode->Attribute("x") + (std::string)"f";
				std::string tempSizeY = sizeNode->Attribute("y") + (std::string)"f";
				float sizeX = std::stof(tempSizeX.c_str());
				float sizeY = std::stof(tempSizeY.c_str());
				pActor->SetSize(maths::Vec2f(sizeX, sizeY));
			}
		}

		tinyxml2::XMLElement* componentsNode = actorNode->FirstChildElement("Components");
		if (!componentsNode)
		{
			LOG("Actor Factory", "Failed to load actor components");
			return NULL;
		}
		else
		{
			unsigned int numComponents = 0;
		
			tinyxml2::XMLElement* rendCompNode = componentsNode->FirstChildElement("RenderComponent");
			if (rendCompNode)
			{
				numComponents++;
				Renderable* rendComp = new Renderable(pActor);
				
				// Transform
				//Transform* pTransform = new Transform(glm::vec3(pActor->GetPosX(), pActor->GetPosY(), pActor->GetPosZ()), glm::vec3(1.0f), glm::vec3(scale));
				Transform* pTransform = new Transform;
				pTransform->SetPos(glm::vec3(pActor->GetPosX(), pActor->GetPosY(), pActor->GetPosZ()));
				// Scale
				glm::vec3 scale(1.0f);
				tinyxml2::XMLElement* scaleNode = rendCompNode->FirstChildElement("Scale");
				if (scaleNode != NULL)
				{
					scale.x = std::stof(scaleNode->Attribute("x"));
					scale.y = std::stof(scaleNode->Attribute("y"));
					scale.z = std::stof(scaleNode->Attribute("z"));
				}
				pTransform->SetScale(scale);
				// Rotation
				glm::vec3 rotation(0.0f);
				tinyxml2::XMLElement* rotationNode = rendCompNode->FirstChildElement("Rotation");
				if (rotationNode != NULL)
				{
					rotation.x = std::stof(rotationNode->Attribute("x"));
					rotation.y = std::stof(rotationNode->Attribute("y"));
					rotation.z = std::stof(rotationNode->Attribute("z"));
				}

				pTransform->SetRot(rotation);
				rendComp->SetTransform(pTransform);

				bool isTextureSet = false;
				//bool isColourSet = false;
				// Colour
				// TODO: Colour loading

				// Texture
				tinyxml2::XMLElement* textureNode = rendCompNode->FirstChildElement("Texture");
				if (textureNode != NULL)
				{
					isTextureSet = true;
					std::string texture = textureNode->Attribute("path");
					rendComp->SetTexture(texture);
		/*			if ((pActor->GetWidth() == 0))
						pActor->SetWidth(rendComp->GetTexture()->GetWidth());
					if (pActor->GetHeight() == 0)
						pActor->SetHeight(rendComp->GetTexture()->GetHeight());*/
				}

				// Mesh
				Mesh* pMesh;
				tinyxml2::XMLElement* meshNode = rendCompNode->FirstChildElement("Mesh");
				if (meshNode != NULL)
				{
					std::string meshPathFileName = meshNode->Attribute("path");

					std::string meshPath = liman::g_pApp->GetResCahe()->GetPath(PathType::Meshes);
					std::string meshFile = meshPath + meshPathFileName;

					pMesh = new Mesh(meshFile);
				}
				else
				{
					float posX = pActor->GetPosX();
					float posY = pActor->GetPosY();
					float posZ = pActor->GetPosZ();
					float width = pActor->GetWidth();
					float height = pActor->GetHeight();
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
				rendComp->SetMesh(pMesh);
				
				pActor->AddComponent(rendComp);
			}

			tinyxml2::XMLElement* moveCompNode = componentsNode->FirstChildElement("MovableComponent");
			if (moveCompNode)
			{
				numComponents++;
				Movable* moveComp = new Movable(pActor);
				tinyxml2::XMLElement* velocityNode = moveCompNode->FirstChildElement("Velocity");
				if (!velocityNode)
				{
					LOG("Actor Factory", "Error: Velocity was not set.\n");
					moveComp->SetVelocity(0.0f, 0.0f);
				}
				else
				{
					std::string tempVelStrX = velocityNode->Attribute("x") + (std::string)"f";
					std::string tempVelStrY = velocityNode->Attribute("y") + (std::string)"f";
					float velX = std::stof(tempVelStrX.c_str());
					float velY = std::stof(tempVelStrY.c_str());
					moveComp->SetVelocity(velX, velY);
				}

				tinyxml2::XMLElement* accelNode = moveCompNode->FirstChildElement("Acceleration");
				if (!accelNode)
				{
					LOG("Actor Factory", "Error: Acceleration was not set.\n");
					moveComp->SetAccel(0.0f, 0.0f);
				}
				else
				{
					std::string tempAcccelStrX = accelNode->Attribute("x") + (std::string)"f";
					std::string tempAcccelStrY = accelNode->Attribute("y") + (std::string)"f";
					float accelX = std::stof(tempAcccelStrX.c_str());
					float accelY = std::stof(tempAcccelStrY.c_str());
					moveComp->SetAccel(accelX, accelY);
				}

				tinyxml2::XMLElement* fallingNode = moveCompNode->FirstChildElement("Falling");
				if (fallingNode)
				{
					std::string fallingValue = fallingNode->Attribute("value");
					if (fallingValue == "true") moveComp->SetFalling(true);
					else moveComp->SetFalling(false);
				}

				tinyxml2::XMLElement* staticNode = moveCompNode->FirstChildElement("Static");
				if (staticNode)
				{
					std::string staticValue = staticNode->Attribute("value");
					if (staticValue == "true") moveComp->SetStatic(true);
					else  moveComp->SetStatic(false);
				}

				pActor->AddComponent(moveComp);
			}

			tinyxml2::XMLElement* colCompNode = componentsNode->FirstChildElement("CollisionComponent");
			if (colCompNode)
			{
				numComponents++;

				//std::sting type = colCompNode->FirstChildElement("Type")->Attribute("value");
				ActorComponent* colComp;
				//if (type == "BOX")
				//{
				colComp = new Rectangle(pActor);
				//}
				//else if (type == "BOX")
				//{
				//	colComp = new Rectangle(pActor);
				//}

				pActor->AddComponent(colComp);
			}

		}

		g_pBGL->GetLevelManager()->InsertActor(pActor);

		return pActor;
	}

}