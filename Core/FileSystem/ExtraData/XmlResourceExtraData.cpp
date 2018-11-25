#include "XmlResourceExtraData.h"

namespace liman {

	void XmlResourceExtraData::ParseXml(char* pRawBuffer)
	{
		m_xmlDocument.Parse(pRawBuffer);
	}

	std::string XmlResourceExtraData::VToString() { return "XmlResourceExtraData"; }

}