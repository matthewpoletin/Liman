#pragma once
// LogManager - writes to some output device errors, info & events.

#include <string>

class LogManager;
static LogManager* g_pLogManager = NULL;

class LogManager
{

	enum LogFlag
	{
		NULL_AIM,

		FILE,
		CONSOLE
	};

public:
	LogManager();
	~LogManager() {}

	void SetFlag(LogFlag flag);

	void Init(std::string LogFileName);

	void WriteLog(std::string tag, std::string str);

private:
	LogFlag m_flag;
	std::string m_logFile;

};