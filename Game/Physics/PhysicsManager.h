/**
 * @brief Finds mass center, summarizes applied forces.
 * @file PhysicsManager.h
 * @author matthewpoletin
 */

#pragma once

namespace liman {

	class PhysicsManager {
	public:
		PhysicsManager() = default;

		virtual ~PhysicsManager() = default;

		void UpdateMovables(int deltaTime);

	private:

	};

}