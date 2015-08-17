#pragma once

enum GameState
{
	GS_Invalid,
	GS_Initializing,
	GS_MainMenu,
	GS_LoadingGameEnvironment,
	GS_Running,
	GS_Paused
};