#pragma once
// Actors.h - actor class

#include "../Maths/Maths.h"

#include "ActorType.h"
#include "Components/ActorComponent.h"
#include "Components/ComponentType.h"

//#include "CRenderable.h"

namespace liman {

	typedef unsigned int ActorId;

	class ActorComponent;
	enum ComponentType;

	class Actor
	{
		friend class ActorComponent;
		friend class CMovable;

	public:
		Actor();
		~Actor();

		std::string m_sourceName;
		void SetSource(std::string sourceName) { m_sourceName = sourceName; }
		std::string GetSource() { return m_sourceName; }

		void SetId(ActorId id) { m_id = id; }
		ActorId GetId() { return m_id; }

		void SetType(ActorType actorType) { m_type = actorType; }
		ActorType GetType(void);

		void SetPos(float& x, float& y, float z);
		void SetPos(maths::Vec2f& vec2);
		void SetPos(maths::Vec3f& vec3);
		void SetPosX(float x) { m_pos.x = x; }
		void SetPosY(float y) { m_pos.y = y; }
		void SetPosZ(float z) { m_pos.z = z; }
		inline const maths::Vec3f GetPos() { return m_pos; }
		inline const float GetPosX() { return m_pos.x; }
		inline const float GetPosY() { return m_pos.y; }
		inline const float GetPosZ() { return m_pos.z; }

		void SetSize(maths::Vec2f size) { m_size = size; }
		void SetSize(float width, float height) { SetSize(maths::Vec2f(width, height)); }
		inline const float GetWidth() { return m_size.x; }
		inline const float GetHeight() { return m_size.y; }
		inline const maths::Vec2f GetSize() { return m_size; }

		void Destroy();

		void AddComponent(void* pComponent, ComponentType type) { m_pComps[type] = pComponent; }

		template <typename T>
		void GetComponent(ComponentType compType, T** a)
		{
			*a = (T*)m_pComps[compType];
		}

	private:
		ActorId m_id;
		ActorType m_type;
		void* m_pComps[ComponentType::NUM_COMPONENTS];

		maths::Vec3f m_pos;
		maths::Vec2f m_size;

	};
}