#pragma once

#include "Collidable.h"

namespace liman {

	class Rectangle : public Collidable
	{
	public:
		Rectangle(Actor* pOwner);
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