#pragma once
// Movable.h - movable component class

#include "Actors/Actor.h"
#include "Actors/ActorComponent.h"

#include "Maths/Maths.h"

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

	public:
		virtual bool Init(tinyxml2::XMLElement* pComponentNode) override;
		virtual void Update(int deltaTime) override;
		virtual void GetInfo() override;

		virtual tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;

	public:
		Movable();
		virtual ~Movable() {}

	public:
		float GetVelocityX() { return m_vel.x; }
		float GetVelocityY() { return m_vel.y; }

		void SetVelocity(float x, float y) { m_vel.x = x; m_vel.y = y; }
		void SetVelocityX(float x) { m_vel.x = x; }
		void SetVelocityY(float y) { m_vel.y = y; }
		void AddVelocity(float x, float y) { m_vel += maths::Vec2f(x, y); }

	public:
		float GetAccelX() { return m_accel.x; }
		float GetAccelY() { return m_accel.y; }

		void SetAccel(float x, float y) { m_accel.x = x; m_accel.y = y; }
		void SetAccelX(float x) { m_accel.x = x; }
		void SetAccelY(float y) { m_accel.y = y; }
		void AddAccel(float x, float y) { m_accel += maths::Vec2f(x, y); }

	public:
		void SetStatic(bool isStatic) { m_isStatic = isStatic; }
		bool IsStatic() { return m_isStatic; }

		void SetFalling(bool isFalling) { m_isFalling = isFalling; }
		bool IsFalling(void) { return m_isFalling; }

	private:
		// TIP: moves (true)
		bool m_isStatic;
		// TIP: affected by the Earth gravity
		bool m_isFalling;

		maths::Vec2f m_vel;
		maths::Vec2f m_accel;

	};

}