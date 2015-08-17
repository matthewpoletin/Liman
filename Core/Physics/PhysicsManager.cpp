#include "PhysicsManager.h"

#include "../Game.h"
#include "../Actors/Actor.h"

namespace liman
{

	void PhysicsManager::UpdateMovables(float deltaTime)
	{
		for (ActorId id = INVALID_ACTOR_ID + 1; id < (unsigned int)g_pBGL->GetLevelManager()->GetNumActors(); id++)
		{
			Actor* pActor = g_pBGL->GetLevelManager()->GetActor(id);
			CMovable* moveComp = NULL;
			pActor->GetComponent(MOVABLE, &moveComp);
			if (moveComp != NULL && !moveComp->IsStatic())
			{
				moveComp->OnUpdate(deltaTime);
			}
		}
	}

}