/**
 * @file KeyboardInput.h
 * @author matthewpoletin
 */

#pragma once

#define MAX_KEYS 1024

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace liman {

	class KeyboardInput {
	private:
		bool m_Keys[MAX_KEYS];
		bool m_KeyState[MAX_KEYS];
		bool m_KeyTyped[MAX_KEYS];

	public:
		KeyboardInput();

		virtual ~KeyboardInput() = default;

		bool Init();

		void Update();

	public:
		bool isKeyPressed(unsigned int keycode) const;

		bool isKeyTyped(unsigned int keycode) const;

	private:
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	};

}