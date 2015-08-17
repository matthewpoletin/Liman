#include "ResCache.h"

#include "../Utilities/Memory/Memory.h"

#include "../Utilities/Logger/Log.h"

#include "../Utilities/String/String.h"

#include <algorithm>
#include <cctype>

#include <iostream>

#include "Loaders/DefaultResourceLoader.h"

namespace liman {

	std::string ResCache::GetPath(PathType type)
	{
		std::string result;
	#ifdef _DEBUG
		switch(type)
		{
		case Shaders:
		case Settings:
			result = m_paths[PathType::DevelopmentResources] + m_paths[type];
			break;
		default:
			result = m_paths[PathType::Resources] + m_paths[type];
			break;
		}
	#else
		result = m_paths[PathType::Resources] + m_paths[type];
	#endif
		return result;
	}

	void ResCache::SetPath(PathType type, std::string path)
	{
		if (path.size() <= 0) return;
		if (path.compare(path.size() - 1, 1, "/") != 0)
		{
			path.append("/");
		}
		m_paths[type] = path;
	}


	ResCache::ResCache(const unsigned int sizeInMb)
	{
		m_cacheSize = sizeInMb * 1024 * 1024;				// total memory size
		m_allocated = 0;									// total memory allocated
	}

	ResCache::~ResCache()
	{
		while (!m_lruResources.empty())
		{
			FreeOneResource();
		}
	}

	bool ResCache::MakeRoom(unsigned int size)
	{
		if (size > m_cacheSize)
		{
			return false;
		}

		// return null if there's no possible way to allocate the memory
		while (size > (m_cacheSize - m_allocated))
		{
			// The cache is empty, and there's still not enough room.
			if (m_lruResources.empty())
				return false;

			FreeOneResource();
		}

		return true;
	}

	char* ResCache::Allocate(unsigned int size)
	{
		if (!MakeRoom(size))
			return NULL;

		char *mem = new char[size];
		if (mem)
		{
			m_allocated += size;
		}

		return mem;
	}

	void ResCache::Free(ResHandle* gonner)
	{
		m_lruResources.remove(gonner);
		m_resources.erase(gonner->GetResource()->m_name);
	
		// The resource might still be in use by something,
		// so the cache can't actually count the memory freed until the
		// ResHandle pointing to it is destroyed.
		//m_allocated -= gonner->m_resource.m_size;
		//delete gonner;
	}

	ResHandle* ResCache::Load(Resource* resource, IResourceFile *file)
	{
		// Create a new resource and add it to the lru list and map

		IResourceLoader* loader;
		ResHandle* handle;

		for (ResourceLoaders::iterator it = m_resourceLoaders.begin(); it != m_resourceLoaders.end(); ++it)
		{
			IResourceLoader* testLoader = *it;

			if (WildcardMatch(testLoader->VGetPattern().c_str(), resource->m_name.c_str()))
			{
				loader = testLoader;
				break;
			}
		}

		if (!loader)
		{
			//GCC_ASSERT(loader && _T("Default resource loader not found!"));
			return handle;		// Resource not loaded!
		}

		int rawSize = m_file->GetRawResourceSize(*resource);
		if (rawSize < 0)
		{
			//GCC_ASSERT(rawSize > 0 && "Resource size returned -1 - Resource not found");
			return nullptr;
		}

		int allocSize = rawSize + ((loader->VAddNullZero()) ? (1) : (0));
	
		char* rawBuffer;
		if (loader->VUseRawFile())
		{
			rawBuffer = Allocate(allocSize);
		}
		else
		{
			rawBuffer = NEW char[allocSize];
		}
		memset(rawBuffer, 0, allocSize);

		if (rawBuffer == NULL || m_file->GetRawResource(*resource, rawBuffer) == 0)
		{
			// resource cache out of memory
			return nullptr;
		}

		char* buffer = NULL;
		unsigned int size = 0;

		if (loader->VUseRawFile())
		{
			buffer = rawBuffer;
			handle = NEW ResHandle(*resource, buffer, rawSize, this);
		}
		else
		{
			size = loader->VGetLoadedResourceSize(rawBuffer, rawSize);
			buffer = Allocate(size);
			if (rawBuffer == NULL || buffer == NULL)
			{
				// resource cache out of memory
				return nullptr;
			}
			handle = NEW ResHandle(*resource, buffer, size, this);
			bool success = loader->VLoadResource(rawBuffer, rawSize, handle);

			if (loader->VDiscardRawBufferAfterLoad())
			{
				SAFE_DELETE_ARRAY(rawBuffer);
			}

			if (!success)
			{
				// resource cache out of memory
				return nullptr;
			}
		}

		if (handle)
		{
			m_lruResources.push_front(handle);
			m_resources[resource->m_name] = handle;
		}

		//JB_ASSERT(loader && _T("Default resource loader not found!"));
		return handle;		// ResCache is out of memory!
	}

	ResHandle* ResCache::Find(Resource* resource)
	{
		ResHandleMap::iterator i = m_resources.find(resource->m_name);
		if (i == m_resources.end())
			return nullptr;

		return i->second;
	}

	void ResCache::Update(ResHandle* handle)
	{
		m_lruResources.remove(handle);
		m_lruResources.push_front(handle);
	}

	void ResCache::FreeOneResource()
	{
		ResHandleList::iterator gonner = m_lruResources.end();
		gonner--;

		ResHandle* handle = *gonner;

		m_lruResources.pop_back();

		m_resources.erase(handle->GetResource()->m_name);
	}

	void ResCache::MemoryHasBeenFreed(unsigned int size)
	{
		m_allocated -= size;
	}

	bool ResCache::Init()
	{
		RegisterLoader(NEW DefaultResourceLoader());

		return true;
	}

	void ResCache::RegisterLoader(IResourceLoader* loader)
	{
		m_resourceLoaders.push_front(loader);
	}

	ResHandle* ResCache::GetHandle(Resource* resource)
	{
		ResHandle* handle(Find(resource));
		if (handle == NULL)
		{
			handle = Load(resource, NULL);
			//JB_ASSERT(handle);
		}
		else
		{
			Update(handle);
		}
		return handle;
	}

	//int ResCache::Preload(const std::string pattern, void(*progressCallback)(int, bool &))
	//{
	//
	//}
	//std::vector<std::string> ResCache::Match(const std::string pattern)
	//{
	//
	//}

	void ResCache::Flush(void)
	{
		while (!m_lruResources.empty())
		{
			ResHandle* handle = *(m_lruResources.begin());
			Free(handle);
			m_lruResources.pop_front();
		}
	}

}