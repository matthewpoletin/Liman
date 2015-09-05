#pragma once
// ActorFactory.h - creating actors and its components

#include "../Utilities/Logger/Log.h"

#include <map>
#include <tinyxml2/tinyxml2.h>

#include "../Subsystems/Application.h"
#include "../Subsystems/BaseGameLogic.h"

#include "ComponentFactory.h"
#include "../Actors/Actor.h"

namespace liman {

	class BaseGameLogic;
	extern BaseGameLogic* g_pBGL;

	const ActorId INVALID_ACTOR_ID = 0;

	class ActorFactory
	{
	public:
		ActorFactory();
		~ActorFactory() {}

		Actor* CreateActor(tinyxml2::XMLElement* actorNode, std::string sourceName);
		ActorComponent* CreateComponent(tinyxml2::XMLElement* pCompNode);


		ActorId GetNextActorId() { return ++m_lastActorId; }
		
	private:
		unsigned int m_numActors;
		ActorId m_lastActorId;

		ComponentFactory m_compFactory;

	};

}