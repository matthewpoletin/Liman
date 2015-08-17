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

		friend class Actor;
		friend class CMovable;
		friend class CRenderable;
		friend class Collidable;
	};
}