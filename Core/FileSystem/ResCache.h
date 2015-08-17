#pragma once
// ResCache.h

#include <tinyxml2/tinyxml2.h>

#include <string>

#include <map>
#include <list>

#include "Resource/ResHandle.h"
#include "Loaders/IResourceLoader.h"
#include "Files/IResourceFile.h"

namespace liman {

	class ResHandle;
	class IResourceLoader;

	enum PathType
	{
		//Folders
		Resources = 0,
		DevelopmentResources,
		Saves,
		// Required in development
		Shaders,
		Settings,
		// Stored outside
		Levels,
		Entities,
		Textures,
		Meshes, // models
		Animations,
		Audio,

		MAX_NUM_PATHS
	};

	typedef std::map<std::string, ResHandle*> ResHandleMap;
	typedef std::list<ResHandle*> ResHandleList;
	typedef std::list<IResourceLoader*> ResourceLoaders;


	class ResCache
	{
		friend class ResHandle;

		std::string m_paths[PathType::MAX_NUM_PATHS];
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

		void SetPath(PathType type, std::string path);
		std::string GetPath(PathType type);

		//int Preload(const std::string pattern, void(*progressCallback)(int, bool &));
		//std::vector<std::string> Match(const std::string pattern);

		void Flush(void);

	};

}