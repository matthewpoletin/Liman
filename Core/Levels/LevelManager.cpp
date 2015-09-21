#include "LevelManager.h"

namespace liman {

	extern Application* g_pApp;

	LevelManager::LevelManager()
	{
		m_numActors = INVALID_ACTOR_ID;
	}

	bool LevelManager::Initialize(std::vector<std::string> &levels)
	{
		std::vector<std::string>::iterator i = levels.begin();
		while (i != levels.end())
		{
			m_Levels.push_back(*i);
			++i;
		}
		return true;
	}

	// TODO: Add multiple levels support
	bool LevelManager::LoadLevel(std::string xmlFileName)
	{
		std::string filePath = g_pApp->GetResCahe()->GetPath("Levels");
		std::string xmlFile = filePath + xmlFileName;
		LOG("LevelManager", "Loading level " + xmlFileName);
	
		//XmlResourceLoader::LoadAndReturnRootXmlElement(xmlFile.c_str());

		tinyxml2::XMLDocument doc;
		doc.LoadFile(xmlFile.c_str());

		if (doc.ErrorID() != 0)
		{
			LOG("LevelManager", "File " + xmlFile + " was not found");
			return false;
		}
		else
		{
			tinyxml2::XMLElement* pWorldNode = doc.FirstChildElement("World");
			if (!pWorldNode)
			{
				LOG("LevelManager", "getting root element failed");
				return false;
			}
			else
			{
				std::string path;

				for (tinyxml2::XMLElement* pActorNode = pWorldNode->FirstChildElement(); pActorNode; pActorNode = pActorNode->NextSiblingElement())
				{
					if (pActorNode->FirstChildElement() != NULL)
					{
						g_pApp->GetGameLogic()->GetActorFactory()->CreateActor(pActorNode, std::string(""));
					}
					else
					{
						path = pActorNode->Attribute("resource");
						if (!LoadActor(path))
						{
							LOG("Level manager", "Loading actor " + path + " failed");
						}
					}
				}
			}
		}
		return true;
	}

	bool LevelManager::LoadActor(std::string xmlFileName)
	{
		std::string filePath = g_pApp->GetResCahe()->GetPath("Entities");
		std::string xmlFile = filePath + xmlFileName;
		LOG("LevelManager", "Loading actor from file " + xmlFileName);

		//XmlResourceLoader::LoadAndReturnRootXmlElement(xmlFile.c_str());

		tinyxml2::XMLDocument doc;
		doc.LoadFile(xmlFile.c_str());

		if (doc.ErrorID() != 0)
		{
			LOG("Level manager", "File " + xmlFile + " was not found");
			return false;
		}
		else
		{
			tinyxml2::XMLElement* pActorNode = doc.FirstChildElement("Actor");
			if (!pActorNode)
			{
				LOG("Level manager", "Getting root element failed");
				return false;
			}
			else
			{
				g_pApp->GetGameLogic()->GetActorFactory()->CreateActor(pActorNode, xmlFileName);
			}
		}
		return true;
	}

	void LevelManager::InsertActor(Actor* pActor)
	{
		m_actors.insert(std::make_pair(pActor->GetId(), pActor));
		m_numActors++;
	}

	Actor* LevelManager::GetActor(ActorId id)
	{
		ActorMap::iterator findIt = m_actors.find(id);
		if (findIt != m_actors.end())
			return findIt->second;
		return nullptr;
	}

	void LevelManager::DestroyActor(const ActorId actorId)
	{
		auto findIt = m_actors.find(actorId);
		if (findIt != m_actors.end())
		{
			findIt->second->Destroy();
			m_actors.erase(findIt);
		}
	}

	void LevelManager::GetActorsInfo()
	{
		for (auto actorIt = m_actors.begin(); actorIt != m_actors.end();  ++actorIt)
		{
			Actor* pActor = actorIt->second;

			std::cout << "Actor" << std::endl;
			std::cout << "id: " << pActor->GetId() << std::endl;
			std::cout << "source: " << pActor->GetSource() << std::endl;

			for (auto compTt = pActor->m_components.begin(); compTt != pActor->m_components.end(); ++compTt)
			{
				compTt->second->GetInfo();
			}
		}
	}

}