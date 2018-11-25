/**
 * @brief Actor class
 * @file Actors.h
 * @author matthewpoletin
 */

#pragma once

#include <string>
#include <map>
#include <tinyxml2.h>

#include "ActorComponent.h"

#include "../Maths/Maths.h"
#include "../Utilities/Memory/Memory.h"

namespace liman {

	class ActorComponent;

	typedef unsigned int ActorId;
	typedef unsigned int ComponentId;
	typedef std::map<ComponentId, ActorComponent*> ComponentsMap;

	class Actor {
		friend class ActorComponent;

		friend class LevelManager;

	public:
		Actor();

		~Actor();

		/**
		 * Initialize actor
		 * @param source Source of actor
		 * @return Result
		 */
		bool Init(std::string &source);

		/**
		 * Destroy actor
		 */
		void Destroy();

		// Source name
		std::string m_sourceName;

		/**
		 * Set source name
		 * @param sourceName Source of actor
		 */
		void SetSource(std::string sourceName) { m_sourceName = sourceName; }

		/**
		 * Get source of actor
		 * @return Source of actor
		 */
		std::string GetSource() { return m_sourceName; }

		/**
		 * Set identificator of actor
		 * @param id Identificator of actor
		 */
		void SetId(ActorId id) { m_id = id; }

		/**
		 * Get identificator of actor
		 * @return Identificator of actor
		 */
		ActorId GetId() { return m_id; }

		/**
		 * Add component to actor
		 * @param pComponent Component
		 */
		void AddComponent(ActorComponent* pComponent);

		/**
		 * Get component of actor
		 * @tparam ComponentType Type of component
		 * @param componentStr Name of component type
		 * @return Actor component
		 */
		template<class ComponentType>
		ComponentType* GetComponent(const char* componentStr) {
			ComponentId id = ActorComponent::GetIdFromName(componentStr);

			ComponentsMap::iterator findIt = m_components.find(id);
			if (findIt != m_components.end()) {
				return static_cast<ComponentType*>(findIt->second);
			} else {
				return nullptr;
			}
		}

		/**
		 * Convert Actor to XML
		 * @return XML representation of actor
		 */
		std::string ToXML();

	private:
		// Identificator
		ActorId m_id;
		// Map of actor's components
		ComponentsMap m_components;

		//maths::Vec3f m_pos;
		// Size of actor
		maths::Vec2f m_size;

	};
}
