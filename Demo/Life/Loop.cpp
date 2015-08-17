#include "Loop.h"

/*
#include "Utilities/Logger/Log.h"

#include <Windows.h>

#include "../DemoGame.h"
#include "Actors/Actor.h"
#include "Initialization.h"
#include "Input/KeyboardInput.h"
#include "Input/MouseInput.h"

extern Shader* g_pShader;

using namespace liman;

// TODO: Work on accelerations.
void MovePlayerRight()
{
	CMovable* tempMove;
	g_pBGL->GetLevelManager()->GetActor(g_pBGL->GetLevelManager()->GetPlayerId())->GetComponent(MOVABLE, &tempMove);
	tempMove->MoveX(-10.0f);
	CRenderable* tempRend;
	g_pBGL->GetLevelManager()->GetActor(g_pBGL->GetLevelManager()->GetPlayerId())->GetComponent(RENDERABLE, &tempRend);
	Transform* pTransform = tempRend->GetTransform();
	pTransform->GetPos().x -= 10.0f;
}
void MovePlayerLeft()
{
	CMovable* tempMove;
	g_pBGL->GetLevelManager()->GetActor(g_pBGL->GetLevelManager()->GetPlayerId())->GetComponent(MOVABLE, &tempMove);
	tempMove->MoveX(10.0f);
	CRenderable* tempRend;
	g_pBGL->GetLevelManager()->GetActor(g_pBGL->GetLevelManager()->GetPlayerId())->GetComponent(RENDERABLE, &tempRend);
	Transform* pTransform = tempRend->GetTransform();
	pTransform->GetPos().x += 10.0f;
}

void OnUpPress()
{
	CMovable* tempMove;
	std::cout << "Move up" << std::endl;
	g_pBGL->GetLevelManager()->GetActor(g_pBGL->GetLevelManager()->GetPlayerId())->GetComponent(MOVABLE, &tempMove);
	tempMove->MoveY(10.0f);
}

void OnDownPress()
{
	CMovable* tempMove;
	std::cout << "Move down" << std::endl;
	g_pBGL->GetLevelManager()->GetActor(g_pBGL->GetLevelManager()->GetPlayerId())->GetComponent(MOVABLE, &tempMove);
	tempMove->MoveY(-10.0f);
}

void OnJumpClick()
{
	std::cout << "Jump" << std::endl;
}

void OnLeftPress()
{
	MovePlayerLeft();
}

void OnRightPress()
{
	MovePlayerRight();
}

void OnSpacePress()
{

}

*/