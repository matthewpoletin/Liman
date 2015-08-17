#pragma once
// PhysicsManager - finds mass center, summarizes applied forces

namespace liman
{

	class PhysicsManager
	{
	public:
		PhysicsManager() {}
		virtual ~PhysicsManager() {}

		void UpdateMovables(float deltaTime);

	private:


	};

}