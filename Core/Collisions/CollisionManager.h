#pragma once

#include "../Actors/Actor.h"
#include "Collidable.h"

namespace liman {

	class CollisionManager
	{
	public:
		CollisionManager();
		~CollisionManager();

		void UpdateCollision();

		void CheckCollision(Actor* pActor1, Actor* pPairedActor2);

	private:

	};

}