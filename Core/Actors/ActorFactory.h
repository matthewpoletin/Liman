#pragma once
// ActorFactory.h - creating actors and its components

#include <map>

#include "../Subsystems/BaseGameLogic.h"

#include <tinyxml2/tinyxml2.h>

#include "../Actors/Actor.h"

#include "ActorComponent.h"
#include "../Graphics/Renderable.h"
#include "../Physics/Movable.h"

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

 		ComponentFactory<ActorComponent, ComponentId> m_compFactory;

	};

	typedef ActorComponent* (*CreationFunction(void));
	template <class ActorComponent, class ComponentType>
	ActorComponent* GenericObjectCreationFunction(void) { return new ComponentType; }

	template<class ActorComponent, class ComponentId>
	class ComponentFactory
	{
	public:
		//ComponentFactory();
		//virtual ~ComponentFactory();

		template<class ComponentType>
		bool Register(ComponentId id)
		{
			auto findIt = m_creationFunctions.find(id);
			if (findIt == m_creationFunctions.end())
			{
				m_creationFunctions[id] = &GenericObjectCreationFunction<ActorComponent, ComponentType>;
				return true;
			}

			return false;
		}

	private:
		std::map<ComponentId, CreationFunction> m_creationFunctions;

	};

}