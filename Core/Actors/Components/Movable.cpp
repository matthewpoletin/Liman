#include "Movable.h"

namespace liman {

	const char* Movable::g_Name = "Movable";

	Movable::Movable(Actor* pOwner)
	{
		this->SetOwner(pOwner);

		m_isStatic = true;
		m_isFalling = false;
	}

	Movable::~Movable()
	{

	}

	void Movable::MoveX(float offset)
	{
		m_pOwner->m_pos.x += offset;
	}

	void Movable::MoveY(float offset)
	{
		m_pOwner->m_pos.y += offset;
	}

	void Movable::OnUpdate(float deltaTimeMS)
	{
		float deltaTimeS = 1000 * deltaTimeMS;

		float posX = m_pOwner->m_pos.x;
		float posY = m_pOwner->m_pos.y;

		m_velocityX += m_accelX * deltaTimeMS;
		if (!m_isFalling)
		{
			m_velocityY += m_accelY * deltaTimeMS;
		}
		else
		{
			m_velocityY += (m_accelY - g_gravity) * deltaTimeMS;
		}

		posX += m_velocityX * deltaTimeMS;
		posY += m_velocityY * deltaTimeMS;

		m_pOwner->SetPos(posX, posY, m_pOwner->GetPosZ());
	}

}