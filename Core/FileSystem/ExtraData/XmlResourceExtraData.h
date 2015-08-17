#pragma once

#include "IResourceExtraData.h"

#include <tinyxml2/tinyxml2.h>

namespace liman {

	class XmlResourceExtraData : public IResourceExtraData
	{
		tinyxml2::XMLDocument m_xmlDocument;

	public:
		virtual std::string VToString() { return "XmlResourceExtraData"; }
		void ParseXml(char* pRawBuffer);
		tinyxml2::XMLElement* GetRoot(void) { return m_xmlDocument.RootElement(); }
	};

}