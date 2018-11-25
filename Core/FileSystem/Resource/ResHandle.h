/**
 * @file ResHandle.h
 * @author matthewpoletin
 */

#pragma once

#include "Resource.h"
#include "../ResCache.h"
#include "../ExtraData/IResourceExtraData.h"

namespace liman {

	class ResCache;

	class ResHandle {
		friend class ResourceManager;

	protected:
		Resource* m_pResource;
		char* m_buffer;
		unsigned int m_size;

		IResourceExtraData* m_extra;

		ResCache* m_pResCache;

	public:
		ResHandle(Resource &resource, char* buffer, unsigned int size, ResCache* pResCache);

		~ResHandle();

		std::string GetName() { return m_pResource->m_name; }

		unsigned int GetSize() { return m_size; }

		char* GetBuffer() { return m_buffer; }

		void SetExtra(IResourceExtraData* extra) { m_extra = extra; }

		IResourceExtraData* GetExtra() { return m_extra; }

		Resource* GetResource();
	};

}