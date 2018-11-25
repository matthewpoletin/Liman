#include "LogManager.h"

#include <iostream>

LogManager::LogManager()
{
	m_flag = NULL_AIM;
}

void LogManager::Init(std::string &logFileName)
{
	this->m_logFile = logFileName;

	if (m_logFile.empty())
	{
		m_flag = CONSOLE;
	}
	else
	{
		m_flag = FILE;

		// TODO: file opening
	}
}

void LogManager::SetFlag(LogManager::LogFlag flag) {
}

void LogManager::WriteLog(std::string tag, std::string str)
{
	switch (this->m_flag)
	{
		case FILE:
			break;
		case CONSOLE:
			std::cerr <<  tag << ": " << str << std::endl;
			break;
		case NULL_AIM:
		default:
			std::cerr << "Logger" << ": " << "aim not defined" << std::endl;
			break;
	}
}
