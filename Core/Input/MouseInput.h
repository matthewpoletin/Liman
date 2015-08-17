#pragma once

#define MAX_BUTTONS	32

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace liman {

	class MouseInput
	{
	private:
		bool m_MouseButtons[MAX_BUTTONS];
		bool m_MouseState[MAX_BUTTONS];
		bool m_MouseClicked[MAX_BUTTONS];

		glm::vec2 m_mousePosition;

	public:
		MouseInput();
		~MouseInput();

		bool Init();
		void Update();

	public:
		bool isMouseButtonPressed(unsigned int button) const;
		bool isMouseButtonClicked(unsigned int button) const;
		const glm::vec2& getMousePosition() const;

	private:
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	};

}