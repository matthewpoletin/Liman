#include "PhysicsManager.h"

#include "Application.h"
#include "Actors/Actor.h"

#include "Movable.h"

namespace liman {

	void PhysicsManager::UpdateMovables(int deltaTime) {
		for (ActorId id = INVALID_ACTOR_ID + 1;
			 id < (unsigned int) g_pApp->GetGameLogic()->GetLevelManager()->GetNumActors(); id++) {
			Actor* pActor = g_pApp->GetGameLogic()->GetLevelManager()->GetActor(id);
			auto* moveComp = pActor->GetComponent<Movable>(Movable::g_Name);
			if (moveComp != nullptr && !moveComp->IsStatic()) {
				moveComp->Update(deltaTime);
			}
		}
	}

}