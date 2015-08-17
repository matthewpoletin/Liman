// Rectangle Collision  checking & reaction prototype
// Copyright Matthew Poletin
// March 2015
// Any unauthorized copying, borrowing or redistribution allowed.
// www.matthewpoletin. ru

#include <iostream>
#include <stdio.h>

#include "Utilities/Memory/Memory.h"

#include "DemoGame.h"
#include "Subsystems/Application.h"

using namespace liman;

int main(int argc, char** argv)
{
	DemoGame* demo = DemoGame::GetInstance();

	demo->Init();

	// Change to checking gamestate
	while (!liman::g_pApp->GetGraphicsSystem()->GetDisplay()->IsClosed())
	{
		demo->DoLoop();
	}

	demo->DeInit();

	return 0;
}

/*
#include "Subsystems\CollisionManager.h"
#include "Subsystems\PhysicsManager.h"

#include "Actors\Actor.h"
#include "Actors\Collidable.h"

LevelManager* g_pLvlMgr;
CollisionManager* g_pCollMgr;
PhysicsManager* g_pPhysMgr;

void PrintActor(Actor* pActor)
{
	printf("Id:\t\t%d\n", pActor->GetId());
	printf("Position:\t%f\t%f\n", pActor->GetPosX(), pActor->GetPosY());
	printf("Acceleration:\t%f\t%f\n", pActor->GetAccelX(), pActor->GetAccelY());
	printf("Velocity:\t%f\t%f\n", pActor->GetVelX(), pActor->GetVelY());
	printf("Size:\t\t%f\t%f\n", pActor->GetSize().x, pActor->GetSize().y);
	printf("\n");
}

void PrintActors()
{
	for (ActorId id = 1; id < g_pLvlMgr->GetNumActors() + 1; id++)
	{
		PrintActor(g_pLvlMgr->GetActor(id));
	}
}

void AddRectangles(void)
{
	Actor* pActor1 = new Actor(g_pLvlMgr->GetNextActorId());
	pActor1->SetPos(Vec2(3.0, 3.0));
	pActor1->SetAccel(Vec2(0.0, 0.0));
	pActor1->SetVel(Vec2(0.0, 0.0));
	pActor1->SetSize(Vec2(6.0, 6.0));
	Collidable* pCollidable1 = new Collidable(pActor1);
	pActor1->SetCollidableComp(pCollidable1);
	g_pLvlMgr->InsertActor(pActor1);

	Actor* pActor2 = new Actor(g_pLvlMgr->GetNextActorId());
	pActor2->SetPos(Vec2(7.0, 8.0));
	pActor2->SetAccel(Vec2(0.0, 0.0));
	pActor2->SetVel(Vec2(0.0, 0.0));
	pActor2->SetSize(Vec2(6.0, 8.0));
	Collidable* pCollidable2 = new Collidable(pActor2);
	pActor2->SetCollidableComp(pCollidable2);
	g_pLvlMgr->InsertActor(pActor2);

	Actor* pActor3 = new Actor(g_pLvlMgr->GetNextActorId());
	pActor3->SetPos(Vec2(8.0, -3.0));
	pActor3->SetAccel(Vec2(0.0, 0.0));
	pActor3->SetVel(Vec2(0.0, 0.0));
	pActor3->SetSize(Vec2(8.0, 6.0));
	Collidable* pCollidable3 = new Collidable(pActor3);
	pActor3->SetCollidableComp(pCollidable3);
	g_pLvlMgr->InsertActor(pActor3);
}

void Initialize()
{
	g_pLvlMgr = new LevelManager;
	g_pCollMgr = new CollisionManager;
	g_pPhysMgr = new PhysicsManager;

	AddRectangles();

	printf("Initialization Info:\n");
	PrintActors();
}

void Iteration()
{
	g_pCollMgr->UpdateCollision();
	//g_pPhysMgr->
	PrintActors();
}

void Deinitialize()
{
	delete g_pLvlMgr;
	delete g_pCollMgr;
	delete g_pPhysMgr;
}

bool isQuiting;

int main()
{
	Initialize();

	char input;
	isQuiting = false;
	while (!isQuiting)
	{
		input = _getch();
		switch (input)
		{
		
		case 27:
			isQuiting = true;
			break;
		case '2':
			system("cls");
			Iteration();
			break;
		default:
			;
		}
	}

	Deinitialize();

	return 0;
}

*/