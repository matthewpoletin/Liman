#pragma once

#include <string>

namespace liman {

	// 0 ~ 0, 12 ~ pi/2(180 degrees),  24 ~ pi
	enum CollisionSide
	{
		NULL_SIDE = 0,

		TOP_RIGHT = 3,
		RIGHT = 6,
		BOTTOM_RIGHT = 9,
		BOTTOM = 12,
		BOTTOM_LEFT = 15,
		LEFT = 18,
		TOP_LEFT = 21,
		TOP = 24
	};

	std::string SideToString(CollisionSide side);

}