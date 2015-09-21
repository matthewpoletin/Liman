#pragma once
// ActorFactory.h - creating actors and its components

#include "../Utilities/Logger/Log.h"

#include <iostream>
#include <map>
#include <tinyxml2/tinyxml2.h>

#include "../Application.h"
#include "../Subsystems/Logic/BaseLogic.h"

#include "ComponentFactory.h"


#include "ActorComponent.h"
#include "../Actors/Actor.h"
#include "Components/TransformComponent.h"
#include "../Graphics/Renderable.h"
#include "../Physics/Movable.h"
#include "../Collisions/Rectangle.h"

namespace liman {

	const ActorId INVALID_ACTOR_ID = 0;

	class ComponetFactory;

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