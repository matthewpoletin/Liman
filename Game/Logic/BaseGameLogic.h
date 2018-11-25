/**
 * @file BaseGameLogic.h
 * @author matthewpoletin
 */

#pragma once

#include "Subsystems/Logic/BaseLogic.h"

#include "../Collisions/CollisionManager.h"
#include "../Physics/PhysicsManager.h"

namespace liman {

	class BaseGameLogic : public BaseLogic {
	public:
		BaseGameLogic();

		~BaseGameLogic() override = default;

	public:
		bool VInit() override;

	public:
		/**
		 * Get collision manager
		 * @return Collision manager
		 */
		CollisionManager* GetCollisionManager() { return m_pCollisionManager; }

		/**
		 * Get physics manager
		 * @return Physics manager
		 */
		PhysicsManager* GetPhysicsManager() { return m_pPhysicsManager; }

	protected:
		// Collision manager
		CollisionManager* m_pCollisionManager;
		// Physics manager
		PhysicsManager* m_pPhysicsManager;

	};

}
