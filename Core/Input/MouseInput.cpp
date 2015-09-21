#include "MouseInput.h"

#include "../Application.h"

namespace liman {

	extern Application* g_pApp;

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	MouseInput::MouseInput()
	{
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
			m_MouseState[i] = false;
			m_MouseClicked[i] = false;
		}
	}

	void MouseInput::Update()
	{
		for (int i = 0; i < MAX_BUTTONS; i++)
			m_MouseClicked[i] = m_MouseButtons[i] && !m_MouseState[i];
		memcpy(m_MouseState, m_MouseButtons, MAX_BUTTONS);
	}

	bool MouseInput::Init()
	{
		GLFWwindow* pWindow = g_pApp->GetGraphicsSystem()->GetDisplay()->GetWindow();
		glfwSetWindowUserPointer(pWindow, this);
		glfwSetMouseButtonCallback(pWindow, mouse_button_callback);
		glfwSetCursorPosCallback(pWindow, cursor_position_callback);
		return true;
	}

	bool MouseInput::isMouseButtonPressed(unsigned int button) const
	{
		// TODO: Log this!
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseButtons[button];
	}

	bool MouseInput::isMouseButtonClicked(unsigned int button) const
	{
		// TODO: Log this!
		if (button >= MAX_BUTTONS)
			return false;

		return m_MouseClicked[button];
	}

	const glm::vec2& MouseInput::getMousePosition() const
	{
		return m_mousePosition;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		//Window* win = (Window*)glfwGetWindowUserPointer(window);
		MouseInput* mi = g_pApp->GetMouse();
		mi->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		//Window* win = (Window*)glfwGetWindowUserPointer(window);
		MouseInput* mi = g_pApp->GetMouse();
		mi->m_mousePosition.x = (float)xpos;
		mi->m_mousePosition.y = (float)ypos;
	}

}