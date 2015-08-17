#include "InputManager.h"

#include "KeyboardInput.h"
#include "MouseInput.h"

#include "../Game.h"

#include "../Utilities/Logger/Log.h"

namespace liman
{

	InputManager::InputManager()
	{
		for (unsigned int i = 0; i < MAX_KEYS; i++)
			m_KeysUsed[i] = false;
		this->ResetKeys();
	}

	InputManager::~InputManager()
	{

	}

	void InputManager::SetKey(unsigned int keyNum)
	{
		if (keyNum >= MAX_KEYS)
			LOG("Input manager", "key out of range");

		m_KeysUsed[keyNum] = true;
	}

	void InputManager::Update()
	{
		this->HandleKeyboard();
		this->HandleMouse();
	}

	void InputManager::ResetKeys()
	{
		for (unsigned int i = 0; i < MAX_KEYS; i++)
		{
			m_KeysPressed[i] = false;
			m_KeysClicked[i] = false;
		}
	}

	void InputManager::ResetButtons()
	{
		for (unsigned int i = 0; i < MAX_BUTTONS; i++)
		{
			m_ButtonsPressed[i] = false;
			m_ButtonsClicked[i] = false;
		}
	}

	void InputManager::HandleKeyboard()
	{
		this->ResetKeys();

		KeyboardInput* pKeyboard = liman::g_pApp->GetKeyboard();
		liman::g_pApp->GetKeyboard()->Update();
		for (unsigned int keyCounter = 0; keyCounter < MAX_KEYS; keyCounter++)
		{
			m_KeysClicked[keyCounter] = pKeyboard->isKeyTyped(keyCounter);
			m_KeysPressed[keyCounter] = pKeyboard->isKeyPressed(keyCounter);
		}
	}

	void InputManager::HandleMouse()
	{
		this->ResetButtons();

		MouseInput* pMouse = liman::g_pApp->GetMouse();
		pMouse->Update();
	
		for (unsigned int buttonCounter = 0; buttonCounter < MAX_BUTTONS; buttonCounter++)
		{
			m_ButtonsClicked[buttonCounter] = pMouse->isMouseButtonClicked(buttonCounter);
			m_ButtonsPressed[buttonCounter] = pMouse->isMouseButtonPressed(buttonCounter);
		}
	}

	bool InputManager::IsKeyPressed(unsigned int keyNum)
	{
		if (keyNum >= MAX_KEYS)
		{
			LOG("Input manager", "key out of range");
			return false;
		}

		bool result = m_KeysPressed[keyNum] && m_KeysUsed[keyNum];
		if (result) LOG("Input manager", "some key was pressed");
		return result;
	}

	bool InputManager::IsKeyClicked(unsigned int keyNum)
	{
		if (keyNum >= MAX_KEYS)
		{
			LOG("Input manager", "key out of range");
			return false;
		}

		bool result = m_KeysClicked[keyNum] && m_KeysUsed[keyNum];
		if (result)
			LOG("Input manager", "some key was clicked");
		return result;
	}

	bool InputManager::IsButtonPressed(unsigned int buttonNum)
	{
		if (buttonNum >= MAX_BUTTONS)
		{
			LOG("Input manager", "button out of range");
			return false;
		}

		bool result = m_ButtonsPressed[buttonNum] && m_ButtonsUsed[buttonNum];
		if (result) LOG("Input manager", "some button was pressed");
		return result;
	}

	bool InputManager::IsButtonClicked(unsigned int buttonNum)
	{
		if (buttonNum >= MAX_BUTTONS)
		{
			LOG("Input manager", "button out of range");
			return false;
		}

		bool result = m_ButtonsClicked[buttonNum] && m_ButtonsUsed[buttonNum];
		if (result) LOG("Input manager", "some button was clicked");
		return result;
	}

}