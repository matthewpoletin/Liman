/**
 * Liman Game Engine Demo
 * @copyright Copyright Matthew Poletin
 * Any unauthorized copying, borrowing or redistribution allowed.
 * @date March 2015
 * @author matthewpoletin
 * www.matthewpoletin.ru/liman
 */

#include <iostream>
#include <stdio.h>

#include "Game.h"

#include "InputReaction.h"

using namespace liman;

int main(int argc, char** argv) {
	auto* pGame = new Game();

	pGame->VInit();

	// TODO: Change to checking gamestate
	while (pGame->VGetState() == Application::State::S_Running)
	//while (!pGame->GetGraphicsSystem()->GetDisplay()->IsClosed())
	{
		pGame->VDoLoop();
		// TODO: Remake as events reations inside the loop
		TempInputReaction();
	}

	pGame->VDeInit();

	return 0;
}