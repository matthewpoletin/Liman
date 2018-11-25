/**
 * @file XmlResourceExtraData.h
 */

#pragma once

#include <tinyxml2.h>

#include "IResourceExtraData.h"

namespace liman {

	class XmlResourceExtraData : public IResourceExtraData {
		tinyxml2::XMLDocument m_xmlDocument;

	public:
		std::string VToString() override;

		void ParseXml(char* pRawBuffer);

		tinyxml2::XMLElement* GetRoot() { return m_xmlDocument.RootElement(); }
	};

}