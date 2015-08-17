#pragma once
// XmlResourceLoader.h

#include "IResourceLoader.h"
#include <tinyxml2/tinyxml2.h>

#include "../ExtraData/XmlResourceExtraData.h"

namespace liman {

	IResourceLoader* CreateXmlResourceLoader();

	class XmlResourceLoader : public IResourceLoader
	{
	public:
		virtual bool VUseRawFile() { return false; }
		virtual bool VDiscardRawBufferAfterLoad() { return true; }
		virtual unsigned int VGetLoadedResourceSize(char *rawBuffer, unsigned int rawSize) { return rawSize; }
		virtual bool VLoadResource(char *rawBuffer, unsigned int rawSize, ResHandle* handle);
		virtual std::string VGetPattern() { return "*.xml"; }

		// convenience function
		static tinyxml2::XMLElement* LoadAndReturnRootXmlElement(const char* resourceString);
	};

}