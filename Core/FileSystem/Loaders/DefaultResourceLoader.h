//#pragma once
//// DefaultResourceLoader.h
//
//#include "./IResourceLoader.h"
//
//namespace liman {
//
//	class ResHandle;
//	virtual class IResourceLoader;
//
//	class DefaultResourceLoader : public IResourceLoader
//	{
//	public:
//		virtual bool VUseRawFile() { return true; }
//		virtual bool VDiscardRawBufferAfterLoad() { return true; }
//		virtual unsigned int VGetLoadedResourceSize(char *rawBuffer, unsigned int rawSize) { return rawSize; }
//		virtual bool VLoadResource(char *rawBuffer, unsigned int rawSize, ResHandle* handle) { return true; }
//		virtual std::string VGetPattern() { return "*"; }
//	};
//
//}