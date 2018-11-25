/**
 * @file IResourceExtraData.h
 */

#pragma once

#include <string>

namespace liman {

	class IResourceExtraData {
	public:
		virtual std::string VToString() = 0;
	};

}