#include "CollisionSide.h"

namespace liman {

	std::string SideToString(CollisionSide side) {
		if (side == TOP_RIGHT) return "top right";
		else if (side == RIGHT) return "right";
		else if (side == BOTTOM_RIGHT) return "bottom right";
		else if (side == BOTTOM) return "bottom";
		else if (side == BOTTOM_LEFT) return "bottom left";
		else if (side == LEFT) return "left";
		else if (side == TOP_LEFT) return "top left";
		else if (side == TOP) return "top";
		else return "no";
	}

}