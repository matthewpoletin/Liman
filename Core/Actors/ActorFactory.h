#pragma once
// ActorFactory.h - creating actors and its components

#include <map>

#include "../Subsystems/BaseGameLogic.h"

#include <tinyxml2/tinyxml2.h>

#include "../Actors/Actor.h"

#include "Components/ActorComponent.h"
#include "Components/CRenderable.h"
#include "Components/CMovable.h"

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

		ActorId GetNextActorId() { return ++m_lastActorId; }

	private:
		unsigned int m_numActors;

		ActorId m_lastActorId;
	};

}