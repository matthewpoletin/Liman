#pragma once
// Actors.h - actor class

#include <tinyxml2/tinyxml2.h>

#include "ActorComponent.h"

#include "../Maths/Maths.h"
#include "../Utilities/Memory/Memory.h"
#include <string>
#include <map>

namespace liman {

	class ActorComponent;

	typedef unsigned int ActorId;
	typedef unsigned int ComponentId;
	typedef std::map<ComponentId, ActorComponent*> ComponentsMap;

	class Actor
	{
		friend class ActorComponent;

		friend class LevelManager;

	public:
		Actor();
		~Actor();

		bool Init(std::string source);
		void Destroy();

		std::string m_sourceName;
		void SetSource(std::string sourceName) { m_sourceName = sourceName; }
		std::string GetSource() { return m_sourceName; }

		void SetId(ActorId id) { m_id = id; }
		ActorId GetId() { return m_id; }

		void AddComponent(ActorComponent* pComponent);

		template<class ComponentType>
		ComponentType* GetComponent(const char* componentStr)
		{
			ComponentId id = ActorComponent::GetIdFromName(componentStr);

			ComponentsMap::iterator findIt = m_components.find(id);
			if (findIt != m_components.end())
			{
				return static_cast<ComponentType*>(findIt->second);
			}
			else
			{
				return nullptr;
			}
		}

		std::string ToXML();

	private:
		ActorId m_id;
		ComponentsMap m_components;

		//maths::Vec3f m_pos;
		maths::Vec2f m_size;

	};
}