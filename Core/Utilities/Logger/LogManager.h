/**
 * @brief Writes to some output device errors, info & events.
 * @file LogManager.h
 */

#pragma once

#include <string>

class LogManager {

	enum LogFlag {
		NULL_AIM,

		FILE,
		CONSOLE
	};

public:
	LogManager();

	~LogManager() = default;

	void SetFlag(LogFlag flag);

	void Init(std::string &LogFileName);

	void WriteLog(std::string tag, std::string str);

private:
	LogFlag m_flag;
	std::string m_logFile;

};

static LogManager* g_pLogManager = nullptr;
