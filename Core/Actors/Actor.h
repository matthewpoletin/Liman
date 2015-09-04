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
	typedef std::map<ComponentId, ActorComponent*> ComponentsMap;

	class Actor
	{
		friend class ActorComponent;

	public:
		Actor();
		~Actor();

		bool Init(tinyxml2::XMLElement* pActorNode);
		void Destroy();

		std::string m_sourceName;
		void SetSource(std::string sourceName) { m_sourceName = sourceName; }
		std::string GetSource() { return m_sourceName; }

		void SetId(ActorId id) { m_id = id; }
		ActorId GetId() { return m_id; }

		void SetPos(float& x, float& y, float z);
		void SetPos(maths::Vec2f& vec2);
		void SetPos(maths::Vec3f& vec3);
		void SetPosX(float x) { m_pos.x = x; }
		void SetPosY(float y) { m_pos.y = y; }
		void SetPosZ(float z) { m_pos.z = z; }
		inline const maths::Vec3f GetPos() { return m_pos; }
		inline const float GetPosX() { return m_pos.x; }
		inline const float GetPosY() { return m_pos.y; }
		inline const float GetPosZ() { return m_pos.z; }

		void SetSize(maths::Vec2f size) { m_size = size; }
		void SetSize(float width, float height) { SetSize(maths::Vec2f(width, height)); }
		inline const float GetWidth() { return m_size.x; }
		inline const float GetHeight() { return m_size.y; }
		inline const maths::Vec2f GetSize() { return m_size; }

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

		std::string Actor::ToXML();

	private:
		ActorId m_id;
		ComponentsMap m_components;

		maths::Vec3f m_pos;
		maths::Vec2f m_size;

	};
}