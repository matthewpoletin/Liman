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


		tinyxml2::XMLElement* propertiesNode = actorNode->FirstChildElement("Properties");
		if (!propertiesNode)
		{
			LOG("Actor Factory", "Failed to load actor properties");
			return NULL;
		}
		else
		{
			if (!pActor->Init(propertiesNode))
			{
				LOG("Actor Factory", "Actor properties node loading failed");
				return false;
			}
		}

		//--------------------------------------------------------

		tinyxml2::XMLElement* componentsNode = actorNode->FirstChildElement("Components");
		if (!componentsNode)
		{
			LOG("Actor Factory", "Failed to load actor components");
			return NULL;
		}
		else
		{
			tinyxml2::XMLElement* rendCompNode = componentsNode->FirstChildElement("RenderComponent");
			if (rendCompNode)
			{
				Renderable*pRend = new Renderable(pActor);

				if (!pRend->Init(rendCompNode))
				{
					LOG("Actor Factory", "Renderable component loading failed");
					return false;
				}

				pActor->AddComponent(pRend);
			}
				
			tinyxml2::XMLElement* moveCompNode = componentsNode->FirstChildElement("MovableComponent");
			if (moveCompNode)
			{

				Movable* pMoveComp = new Movable(pActor);

				if (!pMoveComp->Init(moveCompNode))
				{
					LOG("Actor Factory", "Movable component loading failed");
					return false;
				}

				pActor->AddComponent(pMoveComp);
			}

			tinyxml2::XMLElement* colCompNode = componentsNode->FirstChildElement("CollisionComponent");
			if (colCompNode)
			{
				//std::sting type = colCompNode->FirstChildElement("Type")->Attribute("value");
				//if (type == "BOX")
				//{
				//colComp = new Rectangle(pActor);
				//}
				//else if (type == "BOX")
				//{
				//	colComp = new Rectangle(pActor);
				//}

				Collidable* pColComp;
				pColComp = new Rectangle(pActor);

				if (!pColComp->Init(moveCompNode))
				{
					LOG("Actor Factory", "Rectangel collidable component loading failed");
					return false;
				}

				pActor->AddComponent(pColComp);
			}
		}

		g_pBGL->GetLevelManager()->InsertActor(pActor);

		return pActor;
	}

}