#pragma once
// LevelManager.h

#include <vector>
#include <map>

#include "../Subsystems/BaseGameLogic.h"
#include "../Actors/Actor.h"

namespace liman {

	typedef std::string Level;

	typedef std::map<ActorId, Actor*> ActorMap;

	class LevelManager
	{
	public:
		LevelManager();
		~LevelManager() {}

		void SetPlayerId(ActorId id) { m_playerId = id; }
		ActorId GetPlayerId() { return m_playerId; }

		const int GetCurrentLevel() const { return m_CurrentLevel; }
		bool Initialize(std::vector<std::string> &levels);

		bool LoadLevel(std::string path);
		bool LoadActor(std::string path);

		void InsertActor(Actor* pActor);

		Actor* GetActor(ActorId id);

		int GetNumActors() { return m_numActors; }
		void IncreaseNumActors() { m_numActors++; }

		void DestroyActor(const ActorId actorId);

		// TIP: Temporary for debug purposes
		void ShowListOfActors();
		void GetActorsInfo();

	//private:
		ActorMap m_actors;
		Actor* m_player;
		ActorId m_playerId;

	private:
		unsigned int m_numActors;

	protected:
		// TIP: List of levels' paths
		std::vector<Level> m_Levels;
		int m_CurrentLevel;

	};

	//const std::vector<Level> &GetLevels() const { return m_Levels; }

}