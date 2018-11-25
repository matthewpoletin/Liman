/**
 * @file InputManager.h
 * @author matthewpoletin
 */

#pragma once

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace liman {

	class InputManager {
	public:
		InputManager();

		virtual ~InputManager();

		void Update();

		void SetKey(unsigned int keyNum);

		void SetButton(unsigned int buttonNum);

		void ResetKeys();

		void ResetButtons();

		bool IsKeyPressed(unsigned int keyNum);

		bool IsKeyClicked(unsigned int keyNum);

		bool IsButtonPressed(unsigned int buttonNum);

		bool IsButtonClicked(unsigned int buttonNum);

	private:
		void HandleKeyboard();

		void HandleMouse();

		bool m_KeysUsed[MAX_KEYS];
		bool m_KeysPressed[MAX_KEYS];
		bool m_KeysClicked[MAX_KEYS];

		bool m_ButtonsUsed[MAX_BUTTONS];
		bool m_ButtonsPressed[MAX_BUTTONS];
		bool m_ButtonsClicked[MAX_BUTTONS];

	};
}