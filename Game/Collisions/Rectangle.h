/**
 * @file Rectangle.h
 * @author matthewpoletin
 */

#pragma once

#include "Collidable.h"

namespace liman {

	class Rectangle : public Collidable {
		friend class Actor;

	public:
		static const char* g_Name;

		const char* GetName() const override { return g_Name; }

		ComponentId GetId() const override { return GetIdFromName(GetName()); }

	public:
		Rectangle();

		~Rectangle() override = default;

	public:
		bool Init(tinyxml2::XMLElement* pComponentNode) override;

		tinyxml2::XMLElement* GenerateXML(tinyxml2::XMLDocument* outDoc) override;

	public:
		void SetSize(float x, float y);

		void SetSize(maths::Vec2f vec2);

		void OffSetSize(float x, float y);

		void OffSetSize(maths::Vec2f vec2);

		maths::Vec2f GetSize();

		float GetSizeX();

		float GetSizeY();

	private:
		maths::Vec2f m_size;

	};

}