/**
 * @brief creating actors and its components
 * @file ActorFactory.h
 * @author matthewpoletin
 */

#pragma once

#include "../Utilities/Logger/Log.h"

#include <iostream>
#include <map>
#include <tinyxml2.h>

#include "../Application.h"
#include "../Subsystems/Logic/BaseLogic.h"

#include "ComponentFactory.h"

#include "ActorComponent.h"
#include "../Actors/Actor.h"
#include "Components/TransformComponent.h"
#include "../Graphics/Renderable.h"

namespace liman {

	const ActorId INVALID_ACTOR_ID = 0;

	class ComponetFactory;

	class ActorFactory {
	public:
		ActorFactory();

		~ActorFactory() = default;

		/**
		 * Create actor from XML node
		 * @param actorNode XML node
		 * @param sourceName Source of actor
		 * @return Created actor
		 */
		Actor* CreateActor(tinyxml2::XMLElement* actorNode, std::string &sourceName);

		/**
		 * Create component of actor from XML node
		 * @param pCompNode Component XML node
		 * @return Created actor component
		 */
		ActorComponent* CreateComponent(tinyxml2::XMLElement* pCompNode);

		/**
		 * Get next actor identificator
		 * @return Next actor identificator
		 */
		ActorId GetNextActorId() { return ++m_lastActorId; }

		ComponentFactory* GetComponentFactory() { return m_pCompFactory; }

	private:
		// Number of actors
		unsigned int m_numActors;
		// Identicator of last created actor
		ActorId m_lastActorId;
		// Component factory
		ComponentFactory* m_pCompFactory;

	};

}