#pragma once
// Transform.h
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "../ActorComponent.h"
#include "../../Maths/Maths.h"
#include "../../Graphics/Transform.h"

namespace liman {
	
	class ActorCompontent;

	class TransformComponent : public ActorComponent
	{
		friend class Actor;

	public:
		static const char* g_Name;
		virtual const char* GetName() const override { return g_Name; }
		virtual ComponentId GetId(void) const override { return GetIdFromName(GetName()); }

	public:
		TransformComponent();
		virtual ~TransformComponent() {}

	public:
		virtual bool Init(tinyxml2::XMLElement* pComponentNode) override;
		virtual tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;
		virtual void GetInfo() override;

	public:
		void SetTransform(Transform* pTransform) { m_pTransform = pTransform; }
		Transform* GetTransform() { return m_pTransform; }
		void UpdateTransform();

	public:
		void SetPos(float& x, float& y, float z);
		void SetPos(maths::Vec2f& vec2);
		void SetPos(maths::Vec3f& vec3);
		void SetPosX(float x) { m_pos.x = x; UpdateTransform(); }
		void SetPosY(float y) { m_pos.y = y; UpdateTransform(); }
		void SetPosZ(float z) { m_pos.z = z; UpdateTransform(); }
		inline const maths::Vec3f GetPos() { return m_pos; }

	public:
		void SetRot(float& x, float& y, float& z);
		void SetRot(maths::Vec3f& rot);
		void SetRotX(float x) { m_rot.x = x; UpdateTransform(); }
		void SetRotY(float y) { m_rot.y = y; UpdateTransform(); }
		void SetRotZ(float z) { m_rot.z = z; UpdateTransform(); }
		maths::Vec3f GetRot(void) { return m_rot; }

	public:
		void SetScale(float& x, float& y, float& z);
		void SetScale(maths::Vec3f& scale);
		void SetScaleX(float x) { m_scale.x = x; UpdateTransform(); }
		void SetScaleY(float y) { m_scale.y = y; UpdateTransform(); }
		void SetScaleZ(float z) { m_scale.z = z; UpdateTransform(); }
		maths::Vec3f GetScale(void) { return m_scale; }

	private:
		maths::Vec3f m_pos;
		maths::Vec3f m_rot;
		maths::Vec3f m_scale;

		Transform* m_pTransform;

	};

}