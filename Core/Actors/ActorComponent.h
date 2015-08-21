#pragma once
// ActorComponent.h - component class

#include "Actor.h"

#include "../Utilities/String/String.h"

namespace liman {

	class Actor;

	typedef unsigned int ComponentId;

	class ActorComponent
	{
		friend class ActorFactory;
		friend class Actor;
		//friend class Movable;
		//friend class Renderable;
		//friend class Collidable;

	public:
		ActorComponent() {}
		virtual ~ActorComponent(void) {}

	public:
		//virtual bool Init(tinyxml2::XMLElement* pComponentNode) = 0;

		virtual ComponentId GetId(void) const { return GetIdFromName(GetName()); }
		virtual const char *GetName() const = 0;
		static ComponentId GetIdFromName(const char* componentStr)
		{
			void* rawId = HashedString::hash_name(componentStr);
			return reinterpret_cast<ComponentId>(rawId);
		}

	protected:
		Actor* m_pOwner;

	public:
		void SetOwner(Actor* pActor) { m_pOwner = pActor; }
		Actor* GetOwner() { return m_pOwner; }
	};
}