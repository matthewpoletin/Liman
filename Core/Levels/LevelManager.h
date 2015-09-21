#pragma once
// LevelManager.h - loading levels, actors and components from files, managing them all

#include "../Utilities/Logger/Log.h"
#include "../Debug/Debug.h"

#include <map>
#include <vector>

#include <tinyxml2/tinyxml2.h>
#include "../FileSystem/Loaders/XmlResourceLoader.h"

#include "../Application.h"
#include "../Subsystems/Logic/BaseLogic.h"

#include "../Actors/Actor.h"

namespace liman {

	typedef std::string Level;

	typedef std::map<ActorId, Actor*> ActorMap;

	class LevelManager
	{
	public:
		LevelManager();
		~LevelManager() {}

		bool Initialize(std::vector<std::string> &levels);
		const std::vector<Level> &GetLevels() const { return m_Levels; }
		const int GetCurrentLevel() const { return m_CurrentLevel; }
		bool LoadLevel(std::string path);

	protected:
		std::vector<Level> m_Levels;
		int m_CurrentLevel;

	public:
		bool LoadActor(std::string path);

		// TODO: Change to tag definition
		void SetPlayerId(ActorId id) { m_playerId = id; }
		ActorId GetPlayerId() { return m_playerId; }

		void InsertActor(Actor* pActor);

		Actor* GetActor(ActorId id);

		int GetNumActors() { return m_numActors; }
		void IncreaseNumActors() { m_numActors++; }

		void DestroyActor(const ActorId actorId);

		void GetActorsInfo();

	//private:
		ActorMap m_actors;
		Actor* m_player;
		ActorId m_playerId;

	private:
		unsigned int m_numActors;


	};

}