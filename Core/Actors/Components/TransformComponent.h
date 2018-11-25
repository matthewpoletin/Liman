/**
 * @brief Transform Component
 * @file TransformComponent.h
 */

#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "../ActorComponent.h"
#include "../../Maths/Maths.h"
#include "../../Graphics/Transform.h"

namespace liman {

	class ActorCompontent;

	class TransformComponent : public ActorComponent {
		friend class Actor;

	public:
		// Name of component
		static const char* g_Name;

		/**
		 * Get name of transform component
		 * @return Name of component
		 */
		const char* GetName() const override { return g_Name; }

		/**
		 * Get id of transform component
		 * @return Id of component
		 */
		ComponentId GetId() const override { return GetIdFromName(GetName()); }

	public:
		TransformComponent();

		~TransformComponent() override = default;

	public:
		bool Init(tinyxml2::XMLElement* pComponentNode) override;

		tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;

		void GetInfo() override;

	public:
		void SetTransform(Transform* pTransform) { m_pTransform = pTransform; }

		Transform* GetTransform() { return m_pTransform; }

		void UpdateTransform();

	public:
		/**
		 * Set XYZ position of transform
		 * @param x Coordinate X
		 * @param y Coordinate Y
		 * @param z Coordinate Z
		 */
		void SetPos(float &x, float &y, float z);

		/**
		 * Set XY position of transform
		 * @param vec2 Coordinates XY
		 */
		void SetPos(maths::Vec2f &vec2);

		/**
		 * * Set XYZ position of transform
		 * @param vec3 Coordinates XYZ
		 */
		void SetPos(maths::Vec3f &vec3);

		/**
		 * Set x position
		 * @param x Coordinate X
		 */
		void SetPosX(float x);

		/**
		 * Set Y position
		 * @param y Coordinate Y
		 */
		void SetPosY(float y);

		/**
		 * Set Z Position
		 * @param z Coordinate Z
		 */
		void SetPosZ(float z);

		/**
		 * Get position of transform component
		 * @return Position of transform
		 */
		inline const maths::Vec3f GetPos() { return m_pos; }

	public:
		/**
		 * Set rotation of transform component
		 * @param x Coordinate X
		 * @param y Coordinate Y
		 * @param z Coordinate Z
		 */
		void SetRot(float &x, float &y, float &z);

		void SetRot(maths::Vec3f &rot);

		void SetRotX(float x) {
			m_rot.x = x;
			UpdateTransform();
		}

		void SetRotY(float y) {
			m_rot.y = y;
			UpdateTransform();
		}

		void SetRotZ(float z) {
			m_rot.z = z;
			UpdateTransform();
		}

		maths::Vec3f GetRot() { return m_rot; }

	public:
		void SetScale(float &x, float &y, float &z);

		void SetScale(maths::Vec3f &scale);

		void SetScaleX(float x) {
			m_scale.x = x;
			UpdateTransform();
		}

		void SetScaleY(float y) {
			m_scale.y = y;
			UpdateTransform();
		}

		void SetScaleZ(float z) {
			m_scale.z = z;
			UpdateTransform();
		}

		maths::Vec3f GetScale() { return m_scale; }

	private:
		// Position
		maths::Vec3f m_pos;
		// Rotation
		maths::Vec3f m_rot;
		// Scale
		maths::Vec3f m_scale;
		// Transform object
		Transform* m_pTransform;

	};

}