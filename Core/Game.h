#pragma once

#include "Subsystems/Application.h"
#include "Subsystems/BaseGameLogic.h"

namespace liman {

	class Game
	{
	private:

	public:
		Game();
		virtual ~Game();

		void Do();

		virtual void Init() {};
		virtual void DoLoop() {};
		virtual void DeInit() {};

	};

}