#pragma once

#include "../Actors/Actor.h"

#include "Collidable.h"
#include "Rectangle.h"

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

	bool IsPointInsideActor(maths::Vec2f point, Actor* pActor);
	maths::Vec2f Points2Vector(maths::Vec2f point1, maths::Vec2f point2);

}