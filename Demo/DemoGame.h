#pragma once

#include "Game.h"

void TempInputReaction();

using namespace liman;

extern Application* g_pApp;

class DemoGame : public Game
{
private:
	static DemoGame* m_instance;

public:
	DemoGame();
	virtual ~DemoGame();

	static DemoGame* GetInstance(void)
	{
		if (!m_instance) m_instance = new DemoGame();
		return m_instance;
	}

public:
	void Init() override;
	void DoLoop() override;
	void DeInit() override;
};