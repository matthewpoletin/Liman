/**
 * @brief Movable actor component
 * @file Movable.h
 * @author matthewpoletin
 */
#pragma once

#include <tinyxml2.h>

#include "Actors/Actor.h"
#include "Actors/ActorComponent.h"

#include "Maths/Maths.h"

namespace liman {

	class Movable : public ActorComponent {
		friend class Actor;

	public:
		static const char* g_Name;

		const char* GetName() const override { return g_Name; }

		ComponentId GetId() const override { return GetIdFromName(GetName()); }

		static float g_gravity;

	public:
		bool Init(tinyxml2::XMLElement* pComponentNode) override;

		void Update(int deltaTime) override;

		void GetInfo() override;

		tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;

	public:
		Movable();

		~Movable() override = default;

	public:
		float GetVelocityX() { return m_vel.x; }

		float GetVelocityY() { return m_vel.y; }

		void SetVelocity(float x, float y) {
			m_vel.x = x;
			m_vel.y = y;
		}

		void SetVelocityX(float x) { m_vel.x = x; }

		void SetVelocityY(float y) { m_vel.y = y; }

		void AddVelocity(float x, float y) { m_vel += maths::Vec2f(x, y); }

	public:
		float GetAccelX() { return m_accel.x; }

		float GetAccelY() { return m_accel.y; }

		void SetAccel(float x, float y) {
			m_accel.x = x;
			m_accel.y = y;
		}

		void SetAccelX(float x) { m_accel.x = x; }

		void SetAccelY(float y) { m_accel.y = y; }

		void AddAccel(float x, float y) { m_accel += maths::Vec2f(x, y); }

	public:
		void SetStatic(bool isStatic) { m_isStatic = isStatic; }

		bool IsStatic() { return m_isStatic; }

		void SetFalling(bool isFalling) { m_isFalling = isFalling; }

		bool IsFalling() { return m_isFalling; }

	private:
		// Is able to move
		bool m_isStatic;
		// Is affected by gravity
		bool m_isFalling;

		// Velocity
		maths::Vec2f m_vel;
		// Acceleration
		maths::Vec2f m_accel;

	};

}