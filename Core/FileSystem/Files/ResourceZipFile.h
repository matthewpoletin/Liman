/**
 * @file ResourceZipFile.h
 */

#pragma once

#include "IResourceFile.h"
#include "Compression/ZipFile.h"

namespace liman {

	class ResourceZipFile : public IResourceFile {
		ZipFile* m_pZipFile;
		std::string m_fileName;

	public:
		explicit ResourceZipFile(std::string &resFileName) {
			m_pZipFile = nullptr;
			m_fileName = resFileName;
		}

		~ResourceZipFile() override = default;

		bool Open() override;

		int GetRawResourceSize(const Resource &resource) override;

		int GetRawResource(const Resource &resource, char* buffer) override;

		int GetNumResources() const override;

		std::string GetResourceName(int num) const override;
	};

}