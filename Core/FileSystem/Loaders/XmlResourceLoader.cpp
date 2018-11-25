#include "XmlResourceLoader.h"

#include "../../Application.h"

namespace liman {

	extern Application* g_pApp;

	bool XmlResourceLoader::VLoadResource(char* rawBuffer, unsigned int rawSize, ResHandle* handle) {
		if (rawSize <= 0)
			return false;

		XmlResourceExtraData* pExtraData = new XmlResourceExtraData();
		pExtraData->ParseXml(rawBuffer);

		handle->SetExtra((XmlResourceExtraData*) (pExtraData));

		return true;
	}

	tinyxml2::XMLElement* XmlResourceLoader::LoadAndReturnRootXmlElement(const char* resourceString) {
		Resource resource(resourceString);
		ResHandle* pResourceHandle = g_pApp->GetResCahe()->GetHandle(&resource);
		XmlResourceExtraData* pExtraData = (XmlResourceExtraData*) (pResourceHandle->GetExtra());
		return pExtraData->GetRoot();
	}

	IResourceLoader* CreateXmlResourceLoader() {
		return new XmlResourceLoader;
	}

}