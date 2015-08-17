#pragma once
// ResourceZipFile.h

#include "IResourceFile.h"

#include "Compression\ZipFile.h"

namespace liman {

	class ResourceZipFile : public IResourceFile
	{
		ZipFile* m_pZipFile;
		std::string m_fileName;

	public:
		ResourceZipFile(std::string resFileName) { m_pZipFile = NULL; m_fileName = resFileName; }
		~ResourceZipFile();

		virtual bool Open();
		virtual int GetRawResourceSize(const Resource& resource);
		virtual int GetRawResource(const Resource& resource, char* buffer);
		virtual int GetNumResources() const;
		virtual std::string GetResourceName(int num) const;
	};

}