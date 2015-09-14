#pragma once
// ActorComponent.h - component class

//#include "Actor.h"

#include "../Utilities/String/String.h"

#include <tinyxml2/tinyxml2.h>

namespace liman {

	class Actor;

	typedef unsigned int ComponentId;

	class ActorComponent
	{
		friend class ActorFactory;
		friend class Actor;

	public:
		ActorComponent() { m_pOwner = nullptr; }
		virtual ~ActorComponent(void) {}

	public:
		virtual bool Init(tinyxml2::XMLElement* pComponentNode) = 0;
		virtual void Update(int deltaTime) {}
		virtual void GetInfo() {}
		//virtual ActorComponent*  GetNewInstance() = 0;

		virtual ComponentId GetId(void) const { return GetIdFromName(GetName()); }
		virtual const char *GetName() const = 0;
		static ComponentId GetIdFromName(const char* componentStr)
		{
            void* rawId = HashedString::hash_name(componentStr);
            long long sig1 = reinterpret_cast<long long> (rawId);
            return static_cast<ComponentId>(sig1);
			//return reinterpret_cast<ComponentId>(rawId);
		}

		virtual tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) = 0;

	protected:
		Actor* m_pOwner;

	public:
		void SetOwner(Actor* pActor) { m_pOwner = pActor; }
		Actor* GetOwner() { return m_pOwner; }
	};
}