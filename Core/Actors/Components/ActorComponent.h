#pragma once
// Component.h - component class

#include "../Actor.h"

namespace liman {

	class Actor;

	typedef long ComponentId;

	class ActorComponent
	{
		ComponentId m_id;

		Actor* m_pOwner;

	public:

		void SetOwner(Actor* pActor) { m_pOwner = pActor; }
		Actor* GetOwner() { return m_pOwner; }

		virtual int GetId() { return m_id; }

		friend class Actor;
		friend class Movable;
		friend class Renderable;
		friend class Collidable;
	};
}