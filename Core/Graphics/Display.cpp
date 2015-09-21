#include "Display.h"

#include "../Utilities/Logger/Log.h"

#include "../Application.h"

namespace liman {

	Display::Display(int width, int height, std::string title, const bool windowType)
	{
		m_width = width;
		m_height = height;
		m_title = title;
		m_windowType = windowType;

		if (!this->Init())
		{
			LOG("Graphics", "Failed to initialize");
			glfwTerminate();
		}
	}

	bool Display::Init()
	{
		// Initialization GLFW + OpenGL
		if (!glfwInit()) exit(EXIT_FAILURE);
		// Setting window parameters

		m_monitorInfo = glfwGetVideoMode(glfwGetPrimaryMonitor());
		// Setting OpenGL parameters
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // максимальная рабочая версия opengl 3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // минимальная рабочая версия opengl 3
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // использовать главный профиль opengl
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // возможность менять размера окна
		// Colour depth
		glfwWindowHint(GLFW_RED_BITS, 8);
		glfwWindowHint(GLFW_GREEN_BITS, 8);
		glfwWindowHint(GLFW_BLUE_BITS, 8);
		glfwWindowHint(GLFW_ALPHA_BITS, 8);
		glfwWindowHint(GLFW_AUX_BUFFERS, 32);

		glfwWindowHint(GLFW_DEPTH_BITS, 16);

		// Windowed
		if (m_windowType == false) m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
		// Fullscreen
		else m_window = glfwCreateWindow(m_monitorInfo->width, m_monitorInfo->height, m_title.c_str(), glfwGetPrimaryMonitor(), nullptr);
		// Preparing window

		if (m_window == NULL)
		{
			LOG("Graphics", "Error: window creation failed.");
			return false;
		}

		glfwMakeContextCurrent(m_window);
		glfwSwapInterval(1);

		glewExperimental = GL_TRUE;

		GLenum status = glewInit();

		if (status != GLEW_OK)
		{
			LOG("Graphics", "Error: GLEW failed to initialize");
			return false;
		}

		// TODO: Integrate into BGL (Window is not closed)
		m_isClosed = false;

		bool bDepthTest = false;
		if (bDepthTest)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		bool bCull = false;
		if (bCull)
		{
			glEnable(GL_CULL_FACE);
			glCullFace(GL_BACK);
		}
		else
		{
			glDisable(GL_CULL_FACE);
		}

		LOG("Graphics", std::string(reinterpret_cast< char const * >(glGetString(GL_VERSION))));
		return true;
	}

	void Display::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a); // установка цвета очистки
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // чистим 
	}

	void Display::Update()
	{

		liman::g_pApp->GetGraphicsSystem()->CheckErrors();

		glfwSwapBuffers(m_window); // меняем задний буфер и передний местами
		glfwPollEvents();
		if (glfwWindowShouldClose(m_window))
			m_isClosed = true;
	}

	bool Display::IsClosed()
	{
		return m_isClosed;
	}

	void Display::Close()
	{
		m_isClosed = true;
	}

	Display::~Display()
	{
		glfwDestroyWindow(m_window); // and context too
		glfwTerminate();
	}

}