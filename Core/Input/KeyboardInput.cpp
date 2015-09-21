#include "KeyboardInput.h"

#include "../Utilities/Logger/Log.h"

#include "../Application.h"

namespace liman {

	extern Application* g_pApp;

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	KeyboardInput::KeyboardInput()
	{
		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
			m_KeyState[i] = false;
			m_KeyTyped[i] = false;
		}
	}

	bool KeyboardInput::Init()
	{
		GLFWwindow* window = g_pApp->GetGraphicsSystem()->GetDisplay()->GetWindow();
		glfwSetKeyCallback(window, key_callback);
		return true;
	}

	void KeyboardInput::Update()
	{
		for (int i = 0; i < MAX_KEYS; i++)
			m_KeyTyped[i] = m_Keys[i] && !m_KeyState[i];
		memcpy(m_KeyState, m_Keys, MAX_KEYS);
	}

	bool KeyboardInput::isKeyPressed(unsigned int keycode) const
	{
		// TODO: Log this!
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}

	bool KeyboardInput::isKeyTyped(unsigned int keycode) const
	{
		// TODO: Log this!
		if (keycode >= MAX_KEYS)
			return false;

		return m_KeyTyped[keycode];
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		//KeyboardInput* ki = (KeyboardInput*)glfwGetWindowUserPointer(window);
		KeyboardInput* ki = g_pApp->GetKeyboard();
		ki->m_Keys[key] = action != GLFW_RELEASE;
	}

}