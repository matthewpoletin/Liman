#pragma once
// ActorType.h - enumeration for actor type.

namespace liman {

	enum ActorType
	{
		NULL_TYPE,

		TRIGGER,		// collidable
		NPC,			// collidable
		PROJECTILE,		// collideble

		PLAYER,			// collideble

		ENEMY,

		NUM_ACTOR_TYPES
	};

}