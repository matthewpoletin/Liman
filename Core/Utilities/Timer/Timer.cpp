#include "Timer.h"
#include <GLFW/glfw3.h>

Timer::Timer(void)
{
	m_time = 0.0;
	m_startTime = 0.0;
	m_stopTime = 0.0;
	m_delta = 0.0;
}

double Timer::GetTime()
{
	return m_time = glfwGetTime() * 1000;
}

void Timer::StartTimer()
{
	m_startTime = glfwGetTime() * 1000;
}

void Timer::StopTimer()
{
	m_stopTime = glfwGetTime() * 1000;
}

double Timer::GetDelta()
{
	return m_delta = m_stopTime - m_startTime;
}