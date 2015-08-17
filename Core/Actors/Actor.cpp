#include "Actor.h"

#include "Components/CRenderable.h"

namespace liman {

	Actor::Actor()
	{
		m_type = NULL_TYPE;

		m_pos.x = 0.0f;
		m_pos.y = 0.0f;
		m_pos.z = 0.0f;

		m_size.x = 0.0f;
		m_size.y = 0.0f;

		for (unsigned int counter = 0; counter < NUM_COMPONENTS; counter++)
			m_pComps[counter] = nullptr;
	}

	void Actor::SetPos(float& posX, float& posY, float posZ)
	{
		m_pos.x = posX;
		m_pos.y = posY;
		m_pos.z = posZ;

		if (m_pComps[RENDERABLE] != nullptr)
		{
			CRenderable* rendComp;
			this->GetComponent(RENDERABLE, &rendComp);

			rendComp->GetTransform()->SetPos(glm::vec3(m_pos.x,m_pos.y, m_pos.z));
		}
	}

	void Actor::SetPos(maths::Vec2f& vec2)
	{
		SetPos(vec2.x, vec2.y, 0.0f);
	}


	void Actor::SetPos(maths::Vec3f& vec3)
	{
		SetPos(vec3.x, vec3.y, vec3.z);
	}

	Actor::~Actor()
	{
		this->Destroy();
	}

	void Actor::Destroy()
	{
		for (unsigned int counter = 0; counter < NUM_COMPONENTS; counter++)
			delete m_pComps[counter];
	}

}