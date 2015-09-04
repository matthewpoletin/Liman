#include "ActorFactory.h"

#include <iostream>

#include "ActorComponent.h"
#include "../Graphics/Renderable.h"
#include "../Physics/Movable.h"
#include "../Collisions/Rectangle.h"

namespace liman {

	ActorFactory::ActorFactory()
	{
		m_numActors = 0;
		m_lastActorId = INVALID_ACTOR_ID;

		m_compFactory.RegisterComponent<Renderable>(ActorComponent::GetIdFromName(Renderable::g_Name));
		m_compFactory.RegisterComponent<Movable>(ActorComponent::GetIdFromName(Movable::g_Name));
	}

	Actor* ActorFactory::CreateActor(tinyxml2::XMLElement* actorNode, std::string sourceName)
	{
		// create the actor instance
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
		// Loop through each child element and load the component
		tinyxml2::XMLElement* componentsNode = actorNode->FirstChildElement("Components");
		if (!componentsNode)
		{
			LOG("Actor Factory", "Failed to load actor components");
			return NULL;
		}
		else
		{
			for (tinyxml2::XMLElement* pCompNode = componentsNode->FirstChildElement(); pCompNode; pCompNode->NextSiblingElement())
			{
				ActorComponent* pComponent = this->CreateComponent(pCompNode);
				if (pComponent)
				{
					pActor->AddComponent(pComponent);
					pComponent->SetOwner(pActor);
				}
				else
				{
					LOG("Actor Factory", "Component loading failed");
					return nullptr;
				}
			}
		}

		g_pBGL->GetLevelManager()->InsertActor(pActor);

		return pActor;
	}

	ActorComponent* ActorFactory::CreateComponent(tinyxml2::XMLElement* pCompNode)
	{
		const char* name = pCompNode->Value();
		ActorComponent* pComponent = m_compFactory.CreateComponent(ActorComponent::GetIdFromName(name));

		// initialize the component if we found one
		if (pComponent)
		{
			if (!pComponent->Init(pCompNode))
			{
				LOG("ActorFactory", "Component failed to initialize: " + std::string(name));
				return nullptr;
			}
		}
		else
		{
			LOG("ActorFactory", "Couldn't find ActorComponent named " + std::string(name));
			return nullptr; 
		}

		return pComponent;
	}

}