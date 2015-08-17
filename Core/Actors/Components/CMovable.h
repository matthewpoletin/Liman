#pragma once
// CMovable.h - movable component class

#include "../Actor.h"
#include "ActorComponent.h"

namespace liman {

	class CMovable : public ActorComponent
	{
		friend class Actor;

	public:
		// TODO: pick up appropriate value
		// TODO: move to developer settings
		float g_gravity = 0.000098f;

		CMovable(Actor* pOwner);
		~CMovable();

		void MoveX(float);
		void MoveY(float);

		float GetVelocityX() { return m_velocityX; }
		float GetVelocityY() { return m_velocityY; }

		void SetVelocity(float x, float y) { m_velocityX = x; m_velocityY = y; }
		void SetVelocityX(float x) { m_velocityX = x; }
		void SetVelocityY(float y) { m_velocityY = y; }

		float GetAccelX() { return m_accelX; }
		float GetAccelY() { return m_accelY; }

		void SetAccel(float x, float y) { m_accelX = x; m_accelY = y; }
		void SetAccelX(float x) { m_accelX = x; }
		void SetAccelY(float y) { m_accelY = y; }

		void SetStatic(bool isStatic) { m_isStatic = isStatic; }
		bool IsStatic() { return m_isStatic; }

		void SetFalling(bool isFalling) { m_isFalling = isFalling; }
		bool IsFalling(void) { return m_isFalling; }

		void OnUpdate(float deltaTime);

	private:
		// TIP: moves (true)
		bool m_isStatic;
		// TIP: affected by the Earth gravity
		bool m_isFalling;

		float m_velocityX;
		float m_velocityY;

		float m_accelX;
		float m_accelY;

	};

}