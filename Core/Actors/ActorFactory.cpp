#include "ActorFactory.h"

namespace liman {

	ActorFactory::ActorFactory()
	{
		m_numActors = 0;
		m_lastActorId = INVALID_ACTOR_ID;

		m_pCompFactory = new ComponentFactory();

		m_pCompFactory->RegisterComponent<TransformComponent>(ActorComponent::GetIdFromName(TransformComponent::g_Name));
		m_pCompFactory->RegisterComponent<Renderable>(ActorComponent::GetIdFromName(Renderable::g_Name));
	}

	Actor* ActorFactory::CreateActor(tinyxml2::XMLElement* pActorNode, std::string sourceName)
	{
		Actor* pActor = new Actor;
		pActor->SetId(GetNextActorId());
		pActor->Init(sourceName);

		for (tinyxml2::XMLElement* pCompNode = pActorNode->FirstChildElement(); pCompNode; pCompNode = pCompNode->NextSiblingElement())
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

		Renderable* pRend = pActor->GetComponent<Renderable>(Renderable::g_Name);
		if (pRend && !(pRend->GetMesh()))
		{
			pRend->UpdateMesh();
		}

		g_pApp->GetGameLogic()->GetLevelManager()->InsertActor(pActor);

		return pActor;
	}

	ActorComponent* ActorFactory::CreateComponent(tinyxml2::XMLElement* pCompNode)
	{
		const char* name = pCompNode->Value();
		ActorComponent* pComponent = m_pCompFactory->CreateComponent(ActorComponent::GetIdFromName(name));

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
			LOG("ActorFactory", "Couldn't find component: " + std::string(name));
			return nullptr; 
		}

		return pComponent;
	}

}