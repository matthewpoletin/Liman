/**
 * @brief Game
 * @file Game.h
 * @author matthewpoletin
 */

#pragma once

#include "Utilities/Logger/Log.h"

#include "Application.h"
#include "Subsystems/Logic/BaseLogic.h"
#include "Logic/BaseGameLogic.h"

namespace liman {

	class Game : public Application {
	public:
		Game();

		virtual ~Game() = default;

	public:
		bool VInit() override;

		void VDoLoop() override;

		bool VDeInit() override;

	public:
		BaseGameLogic* GetGameLogic() override { return m_pLogic; }

	protected:
		BaseGameLogic* m_pLogic;

	};

}