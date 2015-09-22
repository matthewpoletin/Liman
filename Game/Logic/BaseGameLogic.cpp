#include "BaseGameLogic.h"

#include "../Physics/Movable.h"

namespace liman {

	BaseGameLogic::BaseGameLogic()
	{
		m_pCollisionManager = NULL;
		m_pPhysicsManager = NULL;
	}

	bool BaseGameLogic::VInit()
	{
		if (!BaseLogic::VInit())
		{
			return false;
		}
		this->GetActorFactory()->GetComponentFactory()->RegisterComponent<Movable>(ActorComponent::GetIdFromName(Movable::g_Name));
		this->GetActorFactory()->GetComponentFactory()->RegisterComponent<Rectangle>(ActorComponent::GetIdFromName(Rectangle::g_Name));

		m_pCollisionManager = new CollisionManager();

		m_pPhysicsManager = new PhysicsManager();

		return true;
	}

}