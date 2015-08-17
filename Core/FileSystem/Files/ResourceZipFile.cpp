#include "ResourceZipFile.h"

#include "../../Utilities/Memory/Memory.h"

namespace liman {

	bool ResourceZipFile::Open()
	{
		m_pZipFile = NEW ZipFile;

		bool retValue = false;

		return retValue;
	}

	//int ResourceZipFile::GetRawResourceSize(const Resource& resource)
	//{
	//
	//}
	//
	//int ResourceZipFile::GetRawResource(const Resource& resource, char* buffer)
	//{
	//
	//}
	//
	//int ResourceZipFile::GetNumResources() const
	//{
	//
	//}
	//
	//std::string ResourceZipFile::GetResourceName(int num) const
	//{
	//
	//}

}