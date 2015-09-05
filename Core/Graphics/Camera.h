#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar, const glm::vec3& forward, const glm::vec3& up)
	{
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = pos;
		m_forward = forward;
		m_up = up;
	}

	glm::vec3 getPos() { return m_position; }
	glm::vec3 GetUp() { return m_up; }
	glm::vec3 GetForward() { return m_forward; }

	void Move(const glm::vec3& pos, const glm::vec3& forward, const glm::vec3& up)
	{
		m_position = pos;
		m_forward = forward;
		m_up = up;
		
		std::cout << "x: " << m_position.x << "y: " << m_position.y << "z: " << m_position.z << std::endl;
	}

	// [Matt] - Add getter for up and forward later

	inline glm::mat4 GetViewProjection() const
	{
		return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
	}
protected:
private:
	glm::mat4 m_perspective;
	glm::vec3 m_position;
	glm::vec3 m_forward;
	glm::vec3 m_up;
};

