#include "PhysicsManager.h"

#include "../Game.h"
#include "../Actors/Actor.h"

namespace liman
{

	void PhysicsManager::UpdateMovables(int deltaTime)
	{
		for (ActorId id = INVALID_ACTOR_ID + 1; id < (unsigned int)g_pBGL->GetLevelManager()->GetNumActors(); id++)
		{
			Actor* pActor = g_pBGL->GetLevelManager()->GetActor(id);
			Movable* moveComp = pActor->GetComponent<Movable>(Movable::g_Name);
			if (moveComp != NULL && !moveComp->IsStatic())
			{
				moveComp->Update(deltaTime);
			}
		}
	}

}