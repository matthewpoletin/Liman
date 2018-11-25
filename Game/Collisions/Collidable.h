/**
 * @brief Collidable component
 * @file Collidable.h
 * @author matthewpoletin
 */

#pragma once

#include "Actors/Actor.h"
#include "Actors/ActorComponent.h"

#include "CollisionSide.h"

#include "Maths/Maths.h"

namespace liman {

	class Actor;

	class Collidable : public ActorComponent {
	public:
		static const char* g_Name;

		const char* GetName() const override { return g_Name; }

	public:
		Collidable();

		~Collidable() override = default;

		// TIP: reaction to collision
		maths::Vec2f Collide(Actor* pPairedActor, CollisionSide side);

	private:

	protected:
		// TIP: ingame changes to collision effect (events) 
		void OnCollision();

	};
}