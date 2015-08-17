#pragma once
// Log.h - namespace for log, errors and events

#include "LogManager.h"

namespace Log
{
	void Init(std::string logFileName);

	void WriteLog(std::string tag, std::string str);

	void Destroy();
}

#define LOG(tag, str) do { std::string s(str); Log::WriteLog(tag, str); } while (0)

//#define ASSERT(expr) \
//	do \
//	{ \
//		if (!(expr)) \
//		{ \
//			static Logger::ErrorMessenger* pErrorMessenger = GCC_NEW Logger::ErrorMessenger; \
//			pErrorMessenger->Show(#expr, false, __FUNCTION__, __FILE__, __LINE__); \
//		} \
//	} \
//	while (0) \