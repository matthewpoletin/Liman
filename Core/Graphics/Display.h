#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace liman {

	class Display
	{
	private:
		int m_width;
		int m_height;
		std::string m_title;
		bool m_windowType;

		const GLFWvidmode* m_monitorInfo;
		GLFWwindow* m_window;
		bool m_isClosed;

	public:
		Display(int width, int height, std::string title, const bool windowType);
		virtual ~Display();

		void Clear(float r, float g, float b, float a);
		void Update();
		bool IsClosed();
		void Close();

		inline GLFWwindow* GetWindow() { return m_window; }

	private:
		Display(const Display& other) {}
//		Display& operator=(const Display& other) {}

		bool Init();
	};

}