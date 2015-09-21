#pragma once
// ResCache.h

#include <tinyxml2/tinyxml2.h>

#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <cctype>
#include <iostream>

#include "../Application.h"

#include "Resource/ResHandle.h"
#include "Loaders/IResourceLoader.h"
#include "Files/IResourceFile.h"
#include "Loaders/DefaultResourceLoader.h"

#include "../Utilities/Memory/Memory.h"
#include "../Utilities/Logger/Log.h"
#include "../Utilities/String/String.h"

namespace liman {

	class ResHandle;
	class IResourceLoader;

	typedef std::map<std::string, std::string> ResPaths;

	typedef std::map<std::string, ResHandle*> ResHandleMap;
	typedef std::list<ResHandle*> ResHandleList;
	typedef std::list<IResourceLoader*> ResourceLoaders;


	class ResCache
	{
		friend class ResHandle;

		ResPaths m_paths;
		ResHandleMap m_resources;
		ResHandleList m_lruResources;	// least recently used resources
	
		ResourceLoaders m_resourceLoaders;

		IResourceFile* m_file;

		unsigned int m_cacheSize;
		unsigned int m_allocated;

	protected:
		bool MakeRoom(unsigned int size);
		char* Allocate(unsigned int size);
		void Free(ResHandle* gonner);

		ResHandle* Load(Resource* resource, IResourceFile *file);
		ResHandle* Find(Resource* resource);
		void Update(ResHandle* handle);

		void FreeOneResource();
		void MemoryHasBeenFreed(unsigned int size);

	public:
		ResCache(const unsigned int sizeInMb);
		virtual ~ResCache();

		bool Init();

		void RegisterLoader(IResourceLoader* loader);

		ResHandle* GetHandle(Resource * r);

		bool LoadPaths(std::string pathsFileName);
		void SetPath(std::string type, std::string path);
		std::string GetPath(std::string type);

		//int Preload(const std::string pattern, void(*progressCallback)(int, bool &));
		//std::vector<std::string> Match(const std::string pattern);

		void Flush(void);

	};

}