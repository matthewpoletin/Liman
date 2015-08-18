#pragma once

#include <string>
#include <vector>
#include <tinyxml2/tinyxml2.h>

#include <glm/glm.hpp>

namespace liman {

	enum KeyTypes
	{
		UNDEFINED_TYPE = 0,

		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,

		JUMP,
		CROUCH,

		SHOOT,

		EXIT = 20,
		PAUSE = EXIT,

		MAX_NUM_KEYS
	};

	struct KeyboardSettings
	{
		char* keys[MAX_NUM_KEYS];
	};

	struct CameraSettings
	{
		glm::vec3 pos;
		glm::vec3 forward;
		glm::vec3 up;
		float zFar;
		float zNear;
		float fov;
	};

	struct DisplaySettings
	{
		int width;
		int height;

		bool isFullscreened; // false == screened
		bool isResizable;

		bool isFramesFixed;
		float maxFramerate;
		float msPerFrame;

		CameraSettings camera;
	};

	struct SoundSettings
	{
		// 0.0 - 1.0
		float musicVolume;
		float sfxVolume;
	};

	struct GameSettings
	{
	public:
		std::string title;

		KeyboardSettings keyboard;
		DisplaySettings display;
		SoundSettings sound;

		std::string level;

		tinyxml2::XMLDocument* m_pDoc;

		GameSettings();
		// TODO:
		~GameSettings() { /*delete(m_pDoc);*/ }

		bool Init(std::string xmlFilePath);
	};

}