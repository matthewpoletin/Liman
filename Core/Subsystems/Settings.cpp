#include "Settings.h"

#include <iostream>
#include <string>

#include "../Utilities/Logger/Log.h"

#include "Application.h"

#include <Windows.h>


namespace liman {

	extern Application* g_pApp;

	GameSettings::GameSettings()
	{
		title = "New Game";

		for (unsigned int typeCounter = UNDEFINED_TYPE + 0; typeCounter < MAX_NUM_KEYS; typeCounter++)
		{
			keyboard.keys[typeCounter] = "";
		}

		keyboard.keys[MOVE_UP] = "W";
		keyboard.keys[MOVE_DOWN] = "S";
		keyboard.keys[MOVE_LEFT] = "A";
		keyboard.keys[MOVE_RIGHT]= "D";
		keyboard.keys[JUMP] = "Space";
		keyboard.keys[CROUCH] = "C";
		keyboard.keys[EXIT] = "Esc";


		display.width = 800;
		display.height = 600;
		display.isFullscreened = true;
		display.isResizable = false;

		display.isFramesFixed = true;
		display.maxFramerate = 60.0f;

		display.camera.pos = glm::vec3(0.0f, 0.0f, 0.0f);
		display.camera.forward = glm::vec3(0.0f, 0.0f, -1.0f);
		display.camera.up = glm::vec3(0.0f, 1.0f, 0.0f);
		display.camera.zFar = 10000.0f;
		display.camera.zNear = 0.001f;
		display.camera.fov = 70.0f;

		m_pDoc = NULL;
	}

	bool GameSettings::Init(std::string xmlFileName)
	{
		LOG("Info", "Loading settings");
		std::string xmlFilePath = g_pApp->GetResCahe()->GetPath(PathType::Settings);
		std::string xmlFile = xmlFilePath + xmlFileName;

		m_pDoc = new tinyxml2::XMLDocument;
		tinyxml2::XMLError err = m_pDoc->LoadFile(xmlFile.c_str());

		if (!m_pDoc && err)
		{
			LOG("File system", "File " + xmlFile + " was not found");
			return false;
		}
		else
		{
			tinyxml2::XMLElement* pRoot = m_pDoc->RootElement();
			if (!pRoot)
				return false;

			tinyxml2::XMLElement* pNode = NULL;
			pNode = pRoot->FirstChildElement("Display");
			if (pNode)
			{
				std::string attribute;

				if (pNode->FirstChildElement("Title")->Attribute("text"))
				{
					title = pNode->FirstChildElement("Title")->Attribute("text");
				}

				if (pNode->FirstChildElement("Size")->Attribute("width"))
				{
					display.width = atoi(pNode->FirstChildElement("Size")->Attribute("width"));
					if (display.width < 800) display.width = 800;
				}

				if (pNode->FirstChildElement("Size")->Attribute("height"))
				{
					display.height = atoi(pNode->FirstChildElement("Size")->Attribute("height"));
					if (display.height < 600) display.height = 600;
				}

				if (pNode->FirstChildElement("Mode")->Attribute("fullscreen"))
				{
					attribute = pNode->FirstChildElement("Mode")->Attribute("fullscreen");
					display.isFullscreened = (attribute == "yes") ? true : false;
				}
			
				if (pNode->FirstChildElement("Border")->Attribute("resizable"))
				{
					attribute = pNode->FirstChildElement("Border")->Attribute("resizable");
					display.isFullscreened = (attribute == "yes") ? true : false;
				}

				if (pNode->FirstChildElement("Framerate")->Attribute("fixed"))
				{
					attribute = pNode->FirstChildElement("Framerate")->Attribute("fixed");
					display.isFramesFixed = (attribute == "yes") ? true : false;
				}

				if (!display.isFramesFixed)
				{
					if (pNode->FirstChildElement("Framerate")->Attribute("value"))
					{
						display.maxFramerate = std::stof(pNode->FirstChildElement("Framerate")->Attribute("value"));
						if (display.maxFramerate < 30.0f) display.maxFramerate = 30.0f;
						display.msPerFrame = 1000 / display.maxFramerate;
					}
				}
				tinyxml2::XMLElement* pCamNode = NULL;
				pCamNode = pNode->FirstChildElement("Camera");
				if (pCamNode)
				{
					display.camera.zFar = std::stof(pCamNode->FirstChildElement("zFar")->Attribute("value"));
					display.camera.zNear = std::stof(pCamNode->FirstChildElement("zNear")->Attribute("value"));
					display.camera.fov = std::stof(pCamNode->FirstChildElement("fov")->Attribute("value"));

					display.camera.pos.x = std::stof(pCamNode->FirstChildElement("Position")->Attribute("x"));
					display.camera.pos.y = std::stof(pCamNode->FirstChildElement("Position")->Attribute("y"));
					display.camera.pos.z = std::stof(pCamNode->FirstChildElement("Position")->Attribute("z"));

					display.camera.forward.x = std::stof(pCamNode->FirstChildElement("Forward")->Attribute("x"));
					display.camera.forward.y = std::stof(pCamNode->FirstChildElement("Forward")->Attribute("y"));
					display.camera.forward.z = std::stof(pCamNode->FirstChildElement("Forward")->Attribute("z"));

					display.camera.up.x = std::stof(pCamNode->FirstChildElement("Up")->Attribute("x"));
					display.camera.up.y = std::stof(pCamNode->FirstChildElement("Up")->Attribute("y"));
					display.camera.up.z = std::stof(pCamNode->FirstChildElement("Up")->Attribute("z"));
				}

			}
			pNode = pRoot->FirstChildElement("Sound");
			if (pNode)
			{
				if (pNode->FirstChildElement("Volume")->Attribute("music"))
				{
					sound.musicVolume = atoi(pNode->Attribute("musicVolume")) / 100.0f;
					sound.sfxVolume = atoi(pNode->Attribute("sfxVolume")) / 100.0f;
				}
			}
			pNode = pRoot->FirstChildElement("Controls");
			if (pNode)
			{
				for (tinyxml2::XMLElement* pKeyNode = pNode->FirstChildElement("Keyboard"); pKeyNode; pKeyNode = pNode->NextSiblingElement())
				{
					if (pKeyNode->Attribute("type") == "move_up") *keyboard.keys[MOVE_UP] = *pKeyNode->Attribute("button");
					else if (pKeyNode->Attribute("type") == "move_down") *keyboard.keys[MOVE_DOWN] = *(pKeyNode->Attribute("button"));
					else if (pKeyNode->Attribute("type") == "move_left") *keyboard.keys[MOVE_LEFT] = *(pKeyNode->Attribute("button"));
					else if (pKeyNode->Attribute("type") == "move_right") *keyboard.keys[MOVE_RIGHT] = *(pKeyNode->Attribute("button"));
					else if (pKeyNode->Attribute("type") == "jump") *keyboard.keys[JUMP] = *(pKeyNode->Attribute("button"));
					else if (pKeyNode->Attribute("type") == "exit") *keyboard.keys[EXIT] = *(pKeyNode->Attribute("button"));
				}

				// TODO: Controllers layots loading
			}
		}

		return true;
	}

}