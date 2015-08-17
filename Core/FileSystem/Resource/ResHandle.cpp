#include "ResHandle.h"

#include "../../Utilities/Memory/Memory.h"

namespace liman {

	ResHandle::ResHandle(Resource& resource, char* buffer, unsigned int size, ResCache* pResCache)
	{
		m_pResource = &resource;
		m_buffer = buffer;
		m_size = size;
		m_pResCache = pResCache;
	}

	ResHandle::~ResHandle()
	{
		SAFE_DELETE_ARRAY(m_buffer);
		m_pResCache->MemoryHasBeenFreed(m_size);
	}

	Resource* ResHandle::GetResource()
	{
		return m_pResource;
	}

}