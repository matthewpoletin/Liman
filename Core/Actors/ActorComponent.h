/**
 * @brief Component class
 * @file ActorComponent.h
 * @author matthewpoletin
 */

#pragma once

#include <tinyxml2.h>

#include "../Utilities/String/String.h"

namespace liman {

	class Actor;

	typedef unsigned int ComponentId;

	class ActorComponent {
		friend class ActorFactory;

		friend class Actor;

	public:
		ActorComponent() { m_pOwner = nullptr; }

		virtual ~ActorComponent() = default;

	public:
		/**
		 * Component initialization
		 * @param pComponentNode XML node
		 * @return Result of initialization
		 */
		virtual bool Init(tinyxml2::XMLElement* pComponentNode) = 0;

		virtual void Update(int deltaTime) {}

		virtual void GetInfo() {}
		//virtual ActorComponent*  GetNewInstance() = 0;

		virtual ComponentId GetId() const { return GetIdFromName(GetName()); }

		virtual const char* GetName() const = 0;

		/**
		 * Generates component's id based on its name
		 * @param componentStr Name of component
		 * @return Component id
		 */
		static ComponentId GetIdFromName(const char* componentStr) {
			void* rawId = HashedString::hash_name(componentStr);
			auto sig1 = reinterpret_cast<long long> (rawId);
			return static_cast<ComponentId>(sig1);
		}

		virtual tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) = 0;

	protected:
		// Owner of component
		Actor* m_pOwner;

	public:
		/**
		 * Set owner of component
		 * @param pActor Actor
		 */
		void SetOwner(Actor* pActor) { m_pOwner = pActor; }

		/**
		 * Get owner of component
		 * @return Owner of component
		 */
		Actor* GetOwner() { return m_pOwner; }

	};
}