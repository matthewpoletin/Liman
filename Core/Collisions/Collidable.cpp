#include "Collidable.h"

#include "../Utilities/Logger/Log.h"

namespace liman {

	const char* Collidable::g_Name = "CollisionComponent";

	Collidable::Collidable(Actor* pOwner)
	{
		this->SetOwner(pOwner);
	}

	Collidable::~Collidable()
	{
	
	}

	// TODO: place somewhere in settings
	const float g_paramColision = 1;

	// TIP: Collision result logic
	maths::Vec2f Collidable::Collide(Actor* pPairedActor, CollisionSide side)
	{
		//#ifdef _DEBUG

		//#endif
		//std::string text = "Actor " + std::to_string(this->GetOwner()->GetId())+ " collided with " + std::to_string(pPairedActor->GetId()) + " on " + SideToString(side) + " side";

		//LOG("Collision Manager", text);

		return maths::Vec2f();
	}

	void Collidable::OnCollision()
	{

		// create collision event
	}

}