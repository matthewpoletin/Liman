// Liman Game Engine Demo
// Copyright Matthew Poletin
// March 2015
// Any unauthorized copying, borrowing or redistribution allowed.
// www.matthewpoletin.ru

#include <iostream>
#include <stdio.h>

#include "Utilities/Memory/Memory.h"

#include "Game.h"

#include "InputReaction.h"

using namespace liman;

int main(int argc, char** argv)
{
	liman::Game* pGame = new Game();

	pGame->VInit();

	// TODO: Change to checking gamestate
	while(pGame->VGetState() == Application::State::S_Running)
	//while (!pGame->GetGraphicsSystem()->GetDisplay()->IsClosed())
	{
		pGame->VDoLoop();
		// TODO: Remake as events reations inside the loop
		TempInputReaction();
	}

	pGame->VDeInit();

	return 0;
}