#pragma once
#include "Subsystems/Logic/BaseLogic.h"

#include "../Collisions/CollisionManager.h"
#include "../Physics/PhysicsManager.h"

namespace liman {

	class BaseGameLogic : public BaseLogic
	{
	public:
		BaseGameLogic();
		virtual ~BaseGameLogic() {}

	public:
		virtual bool VInit(void) override;

	public:
		CollisionManager* GetCollisionManager() { return m_pCollisionManager; }
		PhysicsManager* GetPhysicsManager() { return m_pPhysicsManager; }

	protected:
		CollisionManager* m_pCollisionManager;
		PhysicsManager* m_pPhysicsManager;

	};

}
