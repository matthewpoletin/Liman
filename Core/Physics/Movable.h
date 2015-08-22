#pragma once
// Movable.h - movable component class

#include "../Actors/Actor.h"
#include "../Actors/ActorComponent.h"

#include <tinyxml2/tinyxml2.h>

namespace liman {

	class Movable : public ActorComponent
	{
		friend class Actor;

	public:
		static const char* g_Name;
		virtual const char* GetName() const override { return g_Name; }
		virtual ComponentId GetId(void) const override { return GetIdFromName(GetName()); }

		static float g_gravity;

		Movable(Actor* pOwner);
		~Movable();

		virtual bool Init(tinyxml2::XMLElement* pComponentNode) override;
		void OnUpdate(float deltaTime);

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