#include "LevelManager.h"

#include <tinyxml2/tinyxml2.h>

#include "../Utilities/Logger/Log.h"

#include "../FileSystem/Loaders/XmlResourceLoader.h"

#include "../Subsystems/Application.h"

#include "../Debug/Debug.h"

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
		std::string filePath = g_pApp->GetResCahe()->GetPath(PathType::Levels);
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
						g_pBGL->GetActorFactory()->CreateActor(pActorNode, std::string(""));
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
		std::string filePath = g_pApp->GetResCahe()->GetPath(PathType::Entities);
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
				g_pBGL->GetActorFactory()->CreateActor(pActorNode, xmlFileName);
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
		auto findIt = g_pBGL->GetLevelManager()->m_actors.find(actorId);
		if (findIt != g_pBGL->GetLevelManager()->m_actors.end())
		{
			findIt->second->Destroy();
			g_pBGL->GetLevelManager()->m_actors.erase(findIt);
		}
	}

	void LevelManager::GetActorsInfo()
	{
		console::Line(40, '=');
		Actor* pActor;
		Movable* pMove;
		Renderable* pRend;
		ActorComponent* pCol;
		for (ActorId id = INVALID_ACTOR_ID + 1; id <= m_numActors; id++)
		{
			printf("Actor\n");
			printf("id: %i\n", id);
			pActor = GetActor(id);
			if (pActor != NULL)
			{
				printf("ActorPtr: %p\n", pActor);
				printf("Position: (x)%f, (y)%f, (z)%f\n", pActor->GetPosX(), pActor->GetPosY(), pActor->GetPosZ());
				printf("Size: (x)%f, (y)%f\n", pActor->GetWidth(), pActor->GetHeight());
				console::Line(40, '-');
				printf("Renderable component ");
				pRend = pActor->GetComponent<Renderable>(Renderable::g_Name);
				if (pRend != NULL)
				{
					printf("is set\n");
					printf("Texture file: %s\n", pRend->GetTextureName().c_str());
				}
				else printf("is not set.\n");
				console::Line(40, '-');
				printf("Movable Component ");
				pMove = pActor->GetComponent<Movable>(Movable::g_Name);
				if (pMove != NULL)
				{
					printf("is set.\n");
					printf("Initial velocity: (x)%f, (y)%f\n", pMove->GetVelocityX(), pMove->GetVelocityY());
					printf("Initial acceleration: (x)%f, (y)%f\n", pMove->GetAccelX(), pMove->GetAccelY());
				}
				else printf("is not set.\n");
				

				console::Line(40, '-');
				
				printf("Collision Component ");
				pCol = pActor->GetComponent<Collidable>(Collidable::g_Name);
				if (pCol != NULL)
				{
					printf("is set.\n");

				}
				else printf("is not set.\n");
			}
			console::Line(40, '=');
		}
	}

	void LevelManager::ShowListOfActors()
	{
	#ifdef _DEBUG
		Movable* tempMove;
		Renderable* tempRend;
		printf("List of loaded actors:\n");
		printf("Id\t| Pointer\t| MoveCompPtr\t| RendCompPtr\n");
		printf("-------------------------------------------------------------\n");
		for (ActorMap::iterator it = m_actors.begin(); it != m_actors.end(); it++)
		{
			tempMove = it->second->GetComponent<Movable>(Movable::g_Name);
			tempRend = it->second->GetComponent<Renderable>(Renderable::g_Name);
			printf("%i\t| %p\t| %p\t | %p\n", it->first, it->second, tempMove, tempRend);
		}
	#endif
	}

}