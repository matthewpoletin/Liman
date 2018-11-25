/**
 * @file Display.h
 * @author matthewpoletin
 */

#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace liman {

	class Display {
	private:
		int m_width;
		int m_height;
		std::string m_title;
		bool m_windowType;

		const GLFWvidmode* m_monitorInfo;
		GLFWwindow* m_window;
		bool m_isClosed;

	public:
		/**
		 * Create display
		 * @param width Width
		 * @param height Height
		 * @param title Title
		 * @param windowType Windowed of full screen
		 */
		Display(int width, int height, std::string &title, bool windowType);

		virtual ~Display();

		/**
		 * Clear display color
		 * @param r Color red
		 * @param g Color green
		 * @param b Color blue
		 * @param a Color alpha
		 */
		void Clear(float r, float g, float b, float a);

		/**
		 * Update display
		 */
		void Update();

		/**
		 * Get display state
		 * @return Display state
		 */
		bool IsClosed();

		/**
		 * Close display
		 */
		void Close();

		/**
		 * Get window
		 * @return window
		 */
		inline GLFWwindow* GetWindow() { return m_window; }

	private:
		/**
		 * Init display
		 * @return
		 */
		bool Init();

	};

}