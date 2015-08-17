#include "CMovable.h"

namespace liman {

	CMovable::CMovable(Actor* pOwner)
	{
		this->SetOwner(pOwner);

		m_isStatic = true;
		m_isFalling = false;
	}

	CMovable::~CMovable()
	{

	}

	void CMovable::MoveX(float offset)
	{
		m_pOwner->m_pos.x += offset;
	}

	void CMovable::MoveY(float offset)
	{
		m_pOwner->m_pos.y += offset;
	}

	void CMovable::OnUpdate(float deltaTimeMS)
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