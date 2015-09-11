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