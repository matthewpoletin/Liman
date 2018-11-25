/**
 * @file IResourceLoader.h
 * @author matthewpoletin
 */

#pragma once

#include <string>

#include "../Resource/ResHandle.h"

namespace liman {

	class ResHandle;

	class IResourceLoader {
	public:
		virtual std::string VGetPattern() = 0;

		virtual bool VUseRawFile() = 0;

		virtual bool VDiscardRawBufferAfterLoad() = 0;

		virtual bool VAddNullZero() { return false; }

		virtual unsigned int VGetLoadedResourceSize(char* rawBuffer, unsigned int rawSize) = 0;

		virtual bool VLoadResource(char* rawBuffer, unsigned int rawSize, ResHandle* handle) = 0;
	};

}