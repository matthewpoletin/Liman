/**
 * @brief Namespace for log, errors and events
 * @file Log.h
 * @author matthewpoletin
 */

#pragma once

#include "LogManager.h"

namespace Log {
	/**
	 * Initialize log
	 * @param logFileName Log file name
	 */
	void Init(std::string logFileName);

	/**
	 * Write log message
	 * @param tag Tag
	 * @param str Message
	 */
	void WriteLog(std::string tag, std::string str);

	/**
	 * Destroy log
	 */
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