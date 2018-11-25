/**
 * @file XmlResourceLoader.h
 * @author matthewpoletin
 */

#pragma once

#include <tinyxml2.h>

#include "IResourceLoader.h"

#include "../ExtraData/XmlResourceExtraData.h"

namespace liman {

	IResourceLoader* CreateXmlResourceLoader();

	class XmlResourceLoader : public IResourceLoader {
	public:
		bool VUseRawFile() override { return false; }

		bool VDiscardRawBufferAfterLoad() override { return true; }

		unsigned int VGetLoadedResourceSize(char* rawBuffer, unsigned int rawSize) override { return rawSize; }

		bool VLoadResource(char* rawBuffer, unsigned int rawSize, ResHandle* handle) override;

		std::string VGetPattern() override { return "*.xml"; }

		// convenience function
		static tinyxml2::XMLElement* LoadAndReturnRootXmlElement(const char* resourceString);
	};

}